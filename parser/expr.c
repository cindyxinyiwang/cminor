#include "expr.h"
#include <string.h>
#include <ctype.h>

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right )
{
	struct expr *e = malloc(sizeof(*e));

	e->kind = kind;
	e->left = left;
	e->right = right;

	e->next = 0;

	return e;
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
	e->left = 0;
	e->right = 0;
	e->next = 0;

	return e;

}

struct expr * expr_create_boolean_literal( int c )
{
	struct expr *e = malloc(sizeof(*e));

	e->kind = EXPR_BOOLEAN_VAL;
	e->literal_value = c;
	e->left = 0;
	e->right = 0;
	e->next = 0;

	return e;
}

struct expr * expr_create_integer_literal( int c )
{
	struct expr *e = malloc(sizeof(*e));

	e->kind = EXPR_INT_VAL;
	e->literal_value = c;
	e->left = 0;
	e->right = 0;
	e->next = 0;

	return e;
}


struct expr * expr_create_character_literal( int c )
{
	struct expr *e = malloc(sizeof(*e));

	e->kind = EXPR_CHAR_VAL;
	e->literal_value = c;
	e->left = 0;
	e->right = 0;
	e->next = 0;

	return e;	
}


struct expr * expr_create_string_literal( const char *str )
{
	struct expr *e = malloc(sizeof(*e));

	e->kind = EXPR_STRING_VAL;
	e->string_literal = malloc(sizeof(char) * strlen(str));
	strcpy(e->string_literal, str);
	e->left = 0;
	e->right = 0;
	e->next = 0;
	return e;
}

struct expr * expr_create_function_call( const char *name, struct expr *next ) {
	struct expr *e = malloc(sizeof(*e));

	e->kind = EXPR_FUNCTION_VAL;
	e->name = name;
	e->right = next;
	e->left = 0;
	e->next = 0;

	return e;
}

struct expr * expr_create_array_val( struct expr *next) {
	struct expr *e = malloc(sizeof(*e));

	e->kind = EXPR_ARRAY_VAL;
	e->right = next;
	e->left = 0;
	e->next = 0;

	return e;
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

