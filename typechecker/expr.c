#include "expr.h"
#include <string.h>
#include <ctype.h>
#include "type.h"
#include "decl.h"

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right )
{
	struct expr *e = malloc(sizeof(*e));

	e->kind = kind;
	e->left = left;
	e->right = right;
	e->next = 0;

	e->name = 0;
	e->symbol = 0;
	e->literal_value = 0;
	e->string_literal = 0;

	return e;
}

int expr_compare( struct expr *a, struct expr *b ) {
	if ((!a) && (!b))
		return 1;
	if (!a)
		return 0;
	if (!b)
		return 0;
	if (a->kind != b->kind)
		return 0;
	if (!expr_compare(a->left, b->left))
		return 0;
	if (!expr_compare(a->right, b->right))
		return 0;
	if (!expr_compare(a->next, b->next))
		return 0;
	if (a->literal_value != b->literal_value)
		return 0;

	return 1;
}

/*
Recursively delete an expression tree.
*/

void expr_delete( struct expr *e )
{
	/* Careful: Stop on null pointer. */
	if(!e) return;
	expr_delete(e->next);
	expr_delete(e->left);
	expr_delete(e->right);
	if (e->name) free(e->name);
	if (e->string_literal) free(e->string_literal);
	free ( e );
}

struct expr * expr_create_name( const char *n )
{
	struct expr *e = malloc(sizeof(*e));

	e->kind = EXPR_NAME;
	e->name = n;
	e->left = NULL;
	e->right = NULL;
	e->next = NULL;

	return e;
}

struct expr * expr_create_boolean_literal( int c )
{
	struct expr *e = malloc(sizeof(*e));

	e->kind = EXPR_BOOLEAN_VAL;
	e->literal_value = c;
	e->left = NULL;
	e->right = NULL;
	e->next = NULL;

	return e;
}

struct expr * expr_create_integer_literal( int c )
{
	struct expr *e = malloc(sizeof(*e));

	e->kind = EXPR_INT_VAL;
	e->literal_value = c;
	e->left = NULL;
	e->right = NULL;
	e->next = NULL;

	return e;
}


struct expr * expr_create_character_literal( int c )
{
	struct expr *e = malloc(sizeof(*e));

	e->kind = EXPR_CHAR_VAL;
	e->literal_value = c;
	e->left = NULL;
	e->right = NULL;
	e->next = NULL;

	return e;	
}


struct expr * expr_create_string_literal( const char *str )
{
	struct expr *e = malloc(sizeof(*e));

	e->kind = EXPR_STRING_VAL;
	e->string_literal = malloc(sizeof(char) * strlen(str));
	strcpy(e->string_literal, str);
	e->left = NULL;
	e->right = NULL;
	e->next = NULL;

	return e;
}

struct expr * expr_create_function_call( const char *name, struct expr *next ) {
	struct expr *e = malloc(sizeof(*e));

	e->kind = EXPR_FUNCTION_VAL;
	e->name = name;
	e->right = next;
	e->left = NULL;
	e->next = NULL;

	return e;
}

struct expr * expr_create_array_val( struct expr *next) {
	struct expr *e = malloc(sizeof(*e));

	e->kind = EXPR_ARRAY_VAL;
	e->right = next;
	e->left = NULL;
	e->next = NULL;

	return e;
}

struct type * expr_typecheck( struct expr *e ) {
	if (!e) return type_create(TYPE_VOID, 0, 0);
	struct type *L;
	struct type *R;
	switch (e->kind) {
		case EXPR_INT_VAL:
			return type_create(TYPE_INTEGER, 0, 0);
		case EXPR_NAME:
			return type_copy(e->symbol->type);
		case EXPR_STRING_VAL:
			return type_create(TYPE_STRING, 0, 0);
		case EXPR_CHAR_VAL:
			return type_create(TYPE_CHARACTER, 0, 0);
		case EXPR_BOOLEAN_VAL:
			return type_create(TYPE_BOOLEAN, 0, 0);
		case EXPR_ARRAY_VAL:
		{
			struct expr *vals = e->right;
			struct type *subtype = 0;
			int num_subtype = 0;
			while (vals) {
				struct type *cur_t = expr_typecheck(vals);
				if (!subtype) {
					subtype = cur_t;
				}
				if (!type_compare(subtype, cur_t)) {
					decl_has_error = 1;
					printf("type error: array of element type ");
					type_print(subtype);
					printf(" cannot have expression of type ");
					type_print(cur_t);
					printf("\n");
				}
				num_subtype++;
				vals = vals->next;
			}
			struct type *t = type_create(TYPE_ARRAY, 0, subtype);
			t->num_subtype = expr_create_integer_literal(num_subtype);
			return t;
		}
			//return type_copy(e->symbol->type);
		case EXPR_ARRAY_SUB:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (R->kind != TYPE_INTEGER) {
				decl_has_error = 1;
				printf("type error: cannot use ");
				type_print(R);
				printf(" as index to an array\n");
			}
			if (L->kind != TYPE_ARRAY) {
				decl_has_error = 1;
				printf("type error: access an ");
				type_print(R);
				printf(" as an array\n");
			}
			return type_copy(L->subtype);
		case EXPR_FUNCTION_VAL:
			// need to check function params!!!!!
			param_list_typecheck(e->right, e->symbol->params, e->name);
			return type_copy(e->symbol->type->subtype);
		case EXPR_ADD:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER) {
				decl_has_error = 1;
				printf("type error: cannot add ");
				type_print(L);
				printf(" to a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_INTEGER, 0, 0);
		case EXPR_SUB:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if ( !(L->kind == TYPE_INTEGER && L->kind == TYPE_INTEGER) || R->kind != TYPE_INTEGER) {
				decl_has_error = 1;
				printf("type error: cannot subtract ");
				type_print(L);
				printf(" to a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_INTEGER, 0, 0);
		case EXPR_MUL:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER) {
				decl_has_error = 1;
				printf("type error: cannot multiply ");
				type_print(L);
				printf(" to a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_INTEGER, 0, 0);
		case EXPR_DIV:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER) {
				decl_has_error = 1;
				printf("type error: cannot divide ");
				type_print(L);
				printf(" to a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_INTEGER, 0, 0);
		case EXPR_MODULO:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER) {
				decl_has_error = 1;
				printf("type error: cannot module ");
				type_print(L);
				printf(" to a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_INTEGER, 0, 0);
		case EXPR_EXPO:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER) {
				decl_has_error = 1;
				printf("type error: cannot expo ");
				type_print(L);
				printf(" to a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_INTEGER, 0, 0);
		case EXPR_POST_DECREASE:
			L = expr_typecheck(e->left);
			if (L->kind != TYPE_INTEGER ) {
				decl_has_error = 1;
				printf("type error: cannot decrease a ");
				type_print(L);
				printf("\n");
			}
			return type_create(TYPE_INTEGER, 0, 0);
		case EXPR_POST_INCREASE:
			L = expr_typecheck(e->left);
			if (L->kind != TYPE_INTEGER ) {
				decl_has_error = 1;
				printf("type error: cannot add a ");
				type_print(L);
				printf("\n");
			}
			return type_create(TYPE_INTEGER, 0, 0);
		case EXPR_GE:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER) {
				decl_has_error = 1;
				printf("type error: cannot make greater equal than compare ");
				type_print(L);
				printf(" with a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_BOOLEAN, 0, 0);		
		case EXPR_LE:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER) {
				decl_has_error = 1;
				printf("type error: cannot make less equal compare ");
				type_print(L);
				printf(" with a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_BOOLEAN, 0, 0);		
		case EXPR_GT:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER) {
				decl_has_error = 1;
				printf("type error: cannot make greater than compare ");
				type_print(L);
				printf(" with a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_BOOLEAN, 0, 0);		
		case EXPR_LT:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER) {
				decl_has_error = 1;
				printf("type error: cannot make less than compare ");
				type_print(L);
				printf(" with a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
		case EXPR_AND:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (L->kind != TYPE_BOOLEAN || R->kind != TYPE_BOOLEAN) {
				decl_has_error = 1;
				printf("type error: cannot and ");
				type_print(L);
				printf(" with a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
		case EXPR_NOT:
			R = expr_typecheck(e->right);
			if (R->kind != TYPE_BOOLEAN) {
				decl_has_error = 1;
				printf("type error: cannot not a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
		case EXPR_OR:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (L->kind != TYPE_BOOLEAN || R->kind != TYPE_BOOLEAN) {
				decl_has_error = 1;
				printf("type error: cannot or ");
				type_print(L);
				printf(" with a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
		case EXPR_EQ:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (L->kind == TYPE_FUNCTION || R->kind == TYPE_FUNCTION
				|| L->kind == TYPE_ARRAY || R->kind == TYPE_ARRAY) {
				decl_has_error = 1;
				printf("type error: cannot compare equality ");
				type_print(L);
				printf(" with a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
		case EXPR_NEQ:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (L->kind == TYPE_FUNCTION || R->kind == TYPE_FUNCTION
				|| L->kind == TYPE_ARRAY || R->kind == TYPE_ARRAY) {
				decl_has_error = 1;
				printf("type error: cannot compare non equality ");
				type_print(L);
				printf(" with a ");
				type_print(R);
				printf("\n");
			}
			return type_create(TYPE_BOOLEAN, 0, 0);
		case EXPR_ASSIGN:
			L = expr_typecheck(e->left);
			R = expr_typecheck(e->right);
			if (L->kind == TYPE_FUNCTION || R->kind == TYPE_FUNCTION) {
				decl_has_error = 1;
				printf("type error: cannot assign ");
				type_print(R);
				printf(" to a ");
				type_print(L);
				printf("\n");
			}
			if (!type_compare(L, R)) {
				decl_has_error = 1; 
				printf("type error: cannot assign ");
				type_print(R);
				printf(" to a ");
				type_print(L);
				printf("\n");
			}
			return type_copy(R);
	}
}

void expr_resolve( struct expr *e )
{
	if (!e) return;
	expr_resolve(e->left);
	expr_resolve(e->right);
	
	if (e->kind == EXPR_NAME) {
		struct symbol *s = scope_lookup(e->name);
		if (s) {
			e->symbol = s;
			printf("%s resovles to ", e->name );
			symbol_print( s );
			printf("\n");
		} else {
			printf("variable %s not defined\n", e->name);
			exit(1);
		}
	}

	if (e->kind == EXPR_FUNCTION_VAL) {
		struct symbol *s = scope_lookup(e->name);
		if (s) {
			e->symbol = s;
			printf("%s resovles to ", e->name );
			symbol_print( s );
			printf("\n");			
		} else {
			printf("variable function %s not defined\n", e->name);
			exit(1);
		}
	}

	expr_resolve(e->next);
}

void expr_print( struct expr *e )
{
	if (!e) return;
	switch(e->kind) {
		case EXPR_ADD:
			printf("(");
			expr_print(e->left);
			printf("+");
			expr_print(e->right);
			printf(")");
			break;
		case EXPR_SUB:
			printf("(");
			expr_print(e->left);
			printf("-");
			expr_print(e->right);
			printf(")");
			break;
		case EXPR_MUL:
			printf("(");
			expr_print(e->left);
			printf("*");
			expr_print(e->right);
			printf(")");
			break;
		case EXPR_DIV:
			printf("(");
			expr_print(e->left);
			printf("/");
			expr_print(e->right);
			printf(")");
			break;
		case EXPR_POST_DECREASE:
			printf("(");
			expr_print(e->left);
			printf("--");
			printf(")");
			break;
		case EXPR_POST_INCREASE:
			printf("(");
			expr_print(e->left);
			printf("++");
			printf(")");
			break;
		case EXPR_EXPO:
			printf("(");
			expr_print(e->left);
			printf("^");
			expr_print(e->right);
			printf(")");
			break;
		case EXPR_NOT:
			printf("(");
			printf("!");
			expr_print(e->right);
			printf(")");
			break;
		case EXPR_MODULO:
			printf("(");
			expr_print(e->left);
			printf("%c",'%');
			expr_print(e->right);
			printf(")");
			break;
		case EXPR_GE:
			printf("(");
			expr_print(e->left);
			printf(">=");
			expr_print(e->right);
			printf(")");
			break;
		case EXPR_LE:
			printf("(");
			expr_print(e->left);
			printf("<=");
			expr_print(e->right);
			printf(")");
			break;
		case EXPR_GT:
			printf("(");
			expr_print(e->left);
			printf(">");
			expr_print(e->right);
			printf(")");
			break;
		case EXPR_LT:
			printf("(");
			expr_print(e->left);
			printf("<");
			expr_print(e->right);
			printf(")");
			break;						
		case EXPR_EQ:
			printf("(");
			expr_print(e->left);
			printf("==");
			expr_print(e->right);
			printf(")");
			break;		
		case EXPR_NEQ:
			printf("(");
			expr_print(e->left);
			printf("!=");
			expr_print(e->right);
			printf(")");
			break;	
		case EXPR_AND:
			printf("(");
			expr_print(e->left);
			printf("&&");
			expr_print(e->right);
			printf(")");
			break;
		case EXPR_OR:
			printf("(");
			expr_print(e->left);
			printf("||");
			expr_print(e->right);
			printf(")");
			break;		
		case EXPR_INT_VAL:
			printf("%d", e->literal_value);
			break;
		case EXPR_NAME:
			printf("%s", e->name);
			break;
		case EXPR_STRING_VAL:
			printf("%s", e->string_literal);
			break;
		case EXPR_CHAR_VAL:
			if (iscntrl(e->literal_value)) {
				printf("\'\\");
				switch( e-> literal_value) {					
					case '\n':
						printf("n");
						break;
					case '\0':
						printf("0");
						break;
					default:
						// this should never be executed
						printf("%c", e->literal_value);
						break;
				}
				printf("\'");
			} else {
				printf("\'%c\'", e->literal_value);
			}
			break;
		case EXPR_BOOLEAN_VAL:
			if (e->literal_value) {
				printf("true");
			} else {
				printf("false");
			}
			break;
		case EXPR_ARRAY_VAL:
			printf("{");
			struct expr* vals_array = e->right;
			while(vals_array) {
				expr_print(vals_array);				
				vals_array = vals_array->next;
				if (vals_array) printf(",");
			}
			printf("}");
			break;
		case EXPR_FUNCTION_VAL:
			printf("%s(", e->name);
			struct expr *vals_func = e->right;
			while(vals_func) {
				expr_print(vals_func);
				vals_func = vals_func->next;
				if (vals_func) printf(",");
			}
			printf(")");
			break;
		case EXPR_ASSIGN:
			printf("(");
			expr_print(e->left);
			printf("=");
			expr_print(e->right);
			printf(")");
			break;
		case EXPR_ARRAY_SUB:
			printf("(");
			expr_print(e->left);
			printf("[");
			expr_print(e->right);
			printf("]");
			printf(")");
			break;
	}
}

