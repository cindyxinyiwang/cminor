#ifndef TOKEN_H
#define TOKEN_H

enum token {
	TOKEN_INDENT,
	TOKEN_STRING_LITERAL,
	TOKEN_INTEGER_LITERAL,
	TOKEN_CHAR_LITERAL,
	TOKEN_BOOLEAN_LITERAL,
	TOKEN_KEYWORD,
	TOKEN_GROUP_OP,
	TOKEN_COMP_OP,
	TOKEN_ARITH_OP,
	TOKEN_LOGIC_OP,
	TOKEN_LANGUAGE_SPEC,
	TOKEN_COMMENT,
	TOKEN_WS
};
typedef enum token token_t;
const char* token_string(token_t t, char* yytext, int yyleng);

#endif