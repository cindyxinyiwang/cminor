
#ifndef SYMBOL_H
#define SYMBOL_H

#include "type.h"
#include "stdlib.h"
#include "param_list.h"

typedef enum {
	SYMBOL_LOCAL,
	SYMBOL_PARAM,
	SYMBOL_GLOBAL
} symbol_t;

struct symbol {
	symbol_t kind;
	int which;
	struct type *type;
	char *name;

	struct param_list *params;
};

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name );
void symbol_print( struct symbol *s );

#endif
