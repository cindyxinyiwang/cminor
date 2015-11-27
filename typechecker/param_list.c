#include "param_list.h"
#include "expr.h"
#include "type.h"
#include "decl.h"
#include <stdio.h>

/* 
Create a paramter list node
*/
struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ) {
	struct param_list *p = malloc(sizeof(*p));

	p -> name = name;
	p -> type = type;
	p -> next = next;

	return p;
}

void param_list_delete( struct param_list *a ) {

}

struct param_list * param_list_resolve( struct param_list *a ) {
	struct param_list * params = a;
	while (a) {	
		if (scope_lookup_local(a->name)) {
			printf("resolve error: %s is already declared\n", a->name);
			exit(1);
			//return;
		}
		struct symbol *sym = symbol_create(SYMBOL_PARAM, a->type, a->name);
		scope_bind(a->name, sym);
	 	 a = a->next;
	}
	return a;
}

void param_list_typecheck( struct expr * e, struct param_list *params, char *func_name) {
	while (e && params) {
		struct type *T = expr_typecheck(e);
		if (!type_compare(T, params->type)) {
			decl_has_error = 1;
			printf("type error: cannot pass variable of type ");
			type_print(T);
			printf(" to function %s\n", func_name);

		} 
		e = e->next;
		params = params->next;
	}
	if (e) {
		decl_has_error = 1;
		printf("type error: pass more variables to functions call %s than needed\n", func_name);
	}
	if (params) {
		decl_has_error = 1;
		printf("type error: not enough variables to function call %s\n", func_name);
	}
}

void param_list_print( struct param_list *a ) {
	while (a) {
		printf("%s: ", a->name);
		type_print( a->type );
		if (a->next) printf(",");
		a = a -> next;
	}
}