%{
#include "parser.tab.h"
%}

DIGIT    [0-9]
ID       [a-zA-Z_][a-zA-Z0-9_]*

%%

[ \n\r\t]*		;
{DIGIT}*			return TOKEN_INTEGER;
'([^\\]|\\.)' 		return TOKEN_CHAR;
\"(([^"\n]|([^\\]\\\"))*)\" 		return TOKEN_STRING;
"true" 			return TOKEN_KEYWORD_TRUE;
"false" 		return TOKEN_KEYWORD_FALSE;

"integer" 		return TOKEN_KEYWORD_INTEGER;
"boolean" 		return TOKEN_KEYWORD_BOOLEAN;
"char" 			return TOKEN_KEYWORD_CHAR;
"string" 		return TOKEN_KEYWORD_STRING;
"array" 		return TOKEN_KEYWORD_ARRAY;
"void" 			return TOKEN_KEYWORD_VOID;
"function"		return TOKEN_KEYWORD_FUNCTION;
"if" 			return TOKEN_KEYWORD_IF;
"else" 			return TOKEN_KEYWORD_ELSE;
"for" 			return TOKEN_KEYWORD_FOR;
"print" 		return TOKEN_KEYWORD_PRINT;
"return" 		return TOKEN_KEYWORD_RETURN;

"++" 		return TOKEN_POST_INCREASE;
"--" 		return TOKEN_POST_DECREASE;
\*			return TOKEN_MULTIPLY;
\+			return TOKEN_ADD;
\-			return TOKEN_SUBTRACT;
\/			return TOKEN_DIVIDE;
\^			return TOKEN_EXPO;
\= 			return TOKEN_ASSIGN;
\%			return TOKEN_MODULO;

\!			return TOKEN_NOT;
"<" 		return TOKEN_LT;
">" 		return TOKEN_GT;
"<=" 		return TOKEN_LE;
">=" 		return TOKEN_GE;
"==" 		return TOKEN_EQ;
"!=" 		return TOKEN_NEQ;
"&&" 		return TOKEN_AND;
"||" 		return TOKEN_OR;

\(			return TOKEN_LPAREN;
\)			return TOKEN_RPAREN;
\{			return TOKEN_LBRAC;
\}			return TOKEN_RBRAC;
\[			return TOKEN_LSQBRAC;
\]			return TOKEN_RSQBRAC;
\:			return TOKEN_COLON; 
\;			return TOKEN_SEMI;
\,			return TOKEN_COMA;
{ID}		return TOKEN_ID;

\/\*([^*]*|\*+[^/])*\*\/    /* eat up comments */
\/\/.*  /* eat up inline comments */
<<EOF>>		return TOKEN_END;
.			{ printf("scan error: bad token: %c\n",yytext[0]); exit(1);}
%%

/*
flex calls yywrap() whenever it reaches the end of the current file.
If yywrap returns false to indicate the end of the program.
It could alternatively open up another file and return true,
so that flex would keep going.
*/

int yywrap()
{
	yyin = 0;
	return TOKEN_END;
}


