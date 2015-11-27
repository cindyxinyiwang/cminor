#ifndef EXPR_H
#define EXPR_H

#include "symbol.h"
#include "stdlib.h"
#include "scope.h"
#include "type.h"

typedef enum {
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_DIV,
	EXPR_POST_DECREASE,
	EXPR_POST_INCREASE,
	EXPR_NOT,
	EXPR_MODULO,
	EXPR_GE,
	EXPR_LE,
	EXPR_GT,
	EXPR_LT,
	EXPR_EQ,
	EXPR_NEQ,
	EXPR_AND,
	EXPR_OR,
	EXPR_ASSIGN,
	EXPR_EXPO,

	EXPR_NAME,
	EXPR_INT_VAL,
	EXPR_CHAR_VAL,
	EXPR_BOOLEAN_VAL,
	EXPR_STRING_VAL,
	EXPR_FUNCTION_VAL,
	EXPR_ARRAY_VAL,
	EXPR_ARRAY_SUB
	/* many more types to add here */
} expr_t;

struct expr {
	/* used by all expr types */
	expr_t kind;
	struct expr *left;
	struct expr *right;

	/* used by leaf expr types */
	const char *name;
	struct symbol *symbol;
	int literal_value;
	const char * string_literal;

	/* used by expr_list to define array values
	*/
	struct expr *next;
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );
void expr_delete( struct expr * e );

struct expr * expr_create_name( const char *n );
struct expr * expr_create_boolean_literal( int c );
struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_character_literal( int c );
struct expr * expr_create_string_literal( const char *str );
struct expr * expr_create_function_call( const char *name, struct expr *next );
struct expr * expr_create_array_val( struct expr *next);

void expr_resolve( struct expr *e );
struct type * expr_typecheck( struct expr *e );
void expr_print( struct expr *e );

int expr_compare(struct expr *a, struct expr *b);

#endif
