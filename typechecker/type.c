#include "type.h"
#include "param_list.h"

struct type * type_create( type_kind_t kind, struct param_list *params, struct type *subtype ) {
	struct type *t = malloc(sizeof(*t));

	t-> kind = kind;
	t-> params = params;
	t-> subtype = subtype;
	t-> num_subtype = 0;

	return t;
}


struct type * type_copy( struct type * t ) {
	struct type *t_new = malloc(sizeof(*t));

	t_new->kind = t->kind;
	t_new->params = t->params;
	t_new->subtype = t->subtype;
	t_new->num_subtype = t->num_subtype;

	return t_new;
}

int type_compare( struct type *a, struct type *b ) {
	if ((!a)&&(!b))
		return 1;
	if (!a)
		return 0;
	if (!b)
		return 0;
	if (a->kind != b->kind)
		return 0;
	if (a->params != b->params)
		return 0;
	if (!type_compare(a->subtype, b->subtype))
		return 0;

	//if (!expr_compare(a->num_subtype, b->num_subtype))
	//	return 0;
	return 1;
}

void type_delete( struct type *t ) {
	param_list_delete( t->params );
	type_delete( t->subtype );
	free(t);
}

void type_print( struct type *t ) {
	if(!t) return;
	switch( t->kind ) {
		case TYPE_BOOLEAN:
			printf("boolean");
			break;
		case TYPE_CHARACTER:
			printf("character");
			break;
		case TYPE_INTEGER:
			printf("integer");
			break;
		case TYPE_STRING:
			printf("string");
			break;
		case TYPE_ARRAY:
			printf("array [");
			expr_print(t->num_subtype);
			printf("] ");
			type_print( t->subtype );
			break;
		case TYPE_FUNCTION:
			printf("function ");
			type_print( t->subtype );
			printf("(");
			param_list_print( t-> params);
			printf(")");
			break;
		case TYPE_VOID:
			printf("void");
			break;
	}
}