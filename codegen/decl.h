
#ifndef DECL_H
#define DECL_H

#include "type.h"
#include "stmt.h"
#include "expr.h"
#include "scope.h"
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

// check if decl has error
int decl_has_error;

// lable count
int decl_cur_label;

// local count
int decl_num_local;

// keep the current function symbol
struct symbol *decl_func_sym;

struct decl * decl_create( decl_kind_t kind, char *name, struct type *t, struct expr *v, struct stmt *c, struct decl *next );
void decl_delete( struct decl *d );
void decl_print( struct decl *d, int indent );
void decl_resolve( struct decl *d, symbol_t sym_type );
void decl_typecheck( struct decl *d );

void decl_codegen( struct decl *d, FILE *file );

#endif


