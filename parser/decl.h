
#ifndef DECL_H
#define DECL_H

#include "type.h"
#include "stmt.h"
#include "expr.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum {
	DECL_VAL_INIT,
	DECL_NO_INIT,
	DECL_CODE_INIT
} decl_kind_t;

struct decl {
	decl_kind_t kind;
	char *name;
	struct type *type;
	struct expr *value;
	struct stmt *code;
	struct symbol *symbol;
	struct decl *next;
};

struct decl * decl_create( decl_kind_t kind, char *name, struct type *t, struct expr *v, struct stmt *c, struct decl *next );
void decl_delete( struct decl *d );
void decl_print( struct decl *d, int indent );

#endif


