#include "decl.h"
#include "string.h"

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

void decl_print_indent( indent )
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