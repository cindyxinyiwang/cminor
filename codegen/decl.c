#include "decl.h"
#include "string.h"
#include "symbol.h"
#include "scope.h"
#include "expr.h"
#include <stdio.h>

void decl_preamble(FILE *file, int decl_num_param, int decl_num_local) {
	fprintf(file, "############# preamble before function\n" );
	fprintf(file, "pushq %%rbp\n" );
	fprintf(file, "movq %%rsp, %%rbp\n" );
	int i = 0;
	while (i < decl_num_param) {
		switch(i) {
			case 0:
				fprintf(file, "pushq %%rdi\n" );
				break;
			case 1:
				fprintf(file, "pushq %%rsi\n" );
				break;
			case 2:
				fprintf(file, "pushq %%rdx\n" );
				break;
			case 3:
				fprintf(file, "pushq %%rcx\n" );
				break;
			case 4:
				fprintf(file, "pushq %%r8\n" );
				break;
			case 5:
				fprintf(file, "pushq %%r9\n" );
				break;
		}
		i++;
	}
		
	fprintf(file, "subq $%d, %%rsp\t#allocate local variables\n", 8*decl_num_local );
	fprintf(file, "pushq %%rbx\n" );
	fprintf(file, "pushq %%r12\n" );
	fprintf(file, "pushq %%r13\n" );
	fprintf(file, "pushq %%r14\n" );
	fprintf(file, "pushq %%r15\n" );
}

void decl_postamble(FILE *file, int decl_num_param) {
	fprintf(file, "############# postamble after function\n" );
	fprintf(file, "popq %%r15\n" );
	fprintf(file, "popq %%r14\n" );
	fprintf(file, "popq %%r13\n" );
	fprintf(file, "popq %%r12\n" );
	fprintf(file, "popq %%rbx\n" );
	fprintf(file, "movq %%rbp, %%rsp\n" );
	fprintf(file, "popq %%rbp\n" );
	fprintf(file, "ret\n" );
}

void decl_codegen( struct decl *d, FILE *file )
{
	int decl_num_param;
	while (d) {
		switch( d->kind ) {
			case DECL_VAL_INIT:
				fprintf(file, ".data\n");
				fprintf(file, "%s:\n", d->name);
				switch(d->value->kind) {
					case EXPR_INT_VAL:
						fprintf(file, "\t.quad %d\n", d->value->literal_value);
						break;
					case EXPR_BOOLEAN_VAL:
						fprintf(file, "\t.quad %d\n", d->value->literal_value);
						break;
					case EXPR_CHAR_VAL:
						fprintf(file, "\t.quad %d\n", d->value->literal_value);
						break;
					case EXPR_STRING_VAL:
						fprintf(file, "\t.string %s\n", d->value->string_literal);
						break;
					default:
						printf("error: initializer %s value is not constant.\n", d->name);
						exit(1);
				}			
				break;
			case DECL_NO_INIT:
				printf(";\n");
				break;
			case DECL_CODE_INIT:
				// number of params
				decl_num_param = 0;
				
				struct param_list *p = d->symbol->params;
				while (p) {
					decl_num_param++;
					p = p->next;
				}

				fprintf(file, ".text\n" );
				fprintf(file, ".globl %s\n", d->name);
				fprintf(file, "%s:\n", d->name);
				// preamble
				decl_preamble(file, decl_num_param, d->symbol->num_local);

				fprintf(file, "####### body of function\n" );
				stmt_codegen( d->code, file, decl_num_param );

				// postamble
				decl_postamble(file, decl_num_param);
				break;
		}

		d = d -> next;
	}	
}

struct decl * decl_create( decl_kind_t kind, char *name, struct type *t, struct expr *v, struct stmt *c, struct decl *next )
{
	struct decl *d = malloc(sizeof(*d));

	d-> kind = kind;
	d -> name = malloc(sizeof(char) * strlen(name));
	strcpy( d->name, name );
	d -> type = t;
	d -> value = v;
	d -> code = c;
	d -> next = next;

	return d;
}

void decl_delete( struct decl *d )
{
	if (!d) return;
	free( d-> name );
	type_delete( d->type );
	expr_delete( d->value );
	stmt_delete( d->code );
	decl_delete( d->next );
	free( d );
}

void decl_resolve( struct decl *d, symbol_t sym_type )
{
	if (!d) return;
		
	if (scope_lookup_local(d->name)) {
		printf("resolve error: %s is already declared\n", d->name);
		exit(1);
	}
	struct symbol *sym = symbol_create(sym_type, d->type, d->name);
	scope_bind(d->name, sym);
	d->symbol = sym;
	// resolve type num_subtype for arrays
	struct type *temp_t = d->type;
	while (temp_t) {
		expr_resolve(temp_t->num_subtype);
		temp_t = temp_t->subtype;
	}
	
	if (d->code) {
		decl_num_local = 0;
		scope_enter();
		if (d->type->params) {
			sym->params = d->type->params;
			param_list_resolve(d->type->params);
		}
		
		stmt_resolve(d->code);
		scope_exit();
		sym->num_local = decl_num_local;
	} else if (d->value) {
		expr_resolve(d->value);
	}

	// function prototype 
	if ((!d->code) && d->type->params ) {
		scope_enter();
		sym->params = d->type->params;
		param_list_resolve(d->type->params);
		scope_exit();
	}
	if (d->next)
		decl_resolve(d->next, sym_type);
	
}

// make sure declared array type has a correct size initialization
void decl_array_typecheck( struct type *t, char *name ) {
	if (!t ) return;
	if (t->kind == TYPE_ARRAY) {
		if (!t->num_subtype) {
			decl_has_error = 1;
			printf("type error: array(%s) declaration must have a size value\n", name);
		} else if (expr_typecheck(t->num_subtype)->kind != TYPE_INTEGER) {
			decl_has_error = 1;
			printf("type error: array(%s) size must have integer type\n", name );
		}
	}
	decl_array_typecheck(t->subtype, name);
}

void decl_typecheck( struct decl *d ) {
	if (!d) return;
	if (d->value) {
		struct type *T = expr_typecheck( d-> value );
		if (!type_compare(d->type, T)) {
			printf("type error: cannot initialize variable (%s) of type ", d->name);
			type_print(d->type);
			printf(" and assign it a ");
			type_print( T );
			printf("\n");
		}
	}
	if (d->type->kind == TYPE_ARRAY) {
		// for array
		decl_array_typecheck(d->type, d->name);
	} else if (d->type->kind == TYPE_FUNCTION) {
		// for function return
		decl_array_typecheck(d->type->subtype, d->name);		
	}
	
	if (d->code) {
		decl_func_sym = scope_lookup(d->name);
		stmt_typecheck(d->code);
	}
	if (d->next)
		decl_typecheck(d->next);
}

void decl_print_indent( int indent )
{
	while(indent > 0) {
		printf("\t");
		indent--;
	}
}

void decl_print( struct decl *d, int indent )
{
	while (d) {
		decl_print_indent( indent );
		printf("%s : ", d -> name);
		type_print( d -> type );
		switch( d->kind ) {
			case DECL_VAL_INIT:
				printf("=");
				expr_print( d -> value);
				// if value is none, then it is empty array initialization
				if ( !d-> value ) {
					printf("{}");
				}
				printf(";\n");
				break;
			case DECL_NO_INIT:
				printf(";\n");
				break;
			case DECL_CODE_INIT:
				printf("= {\n");
				stmt_print( d -> code, indent + 1 );
				printf("\n");
				decl_print_indent( indent );
				printf("}\n");
				break;
		}

		d = d -> next;
	}
}