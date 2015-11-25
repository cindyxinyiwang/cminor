/* scanner for cminor */

%{
 #include "token.h"
 #include <stdio.h>
 #include <getopt.h>
%}

DIGIT    [0-9]
ID       [a-zA-Z_][a-zA-Z0-9_]*
KEYWORD  array|boolean|char|else|false|for|foreach|function|if|integer|print|return|string|true|void|while
ARITH_OP "++"|"+"|"--"|"-"|"*"|"/"|"%"|"^"|"="
COMP_OP  "<"|"<="|">"|">="|"=="|"!="
LOGIC_OP "&&"|"||"
GROUP_OP "("|")"|"["|"]"|"{"|"}"
LANGUAGE_SPEC ","|";"|":"
%%

{DIGIT}+    { return TOKEN_INTEGER_LITERAL; }

"true"|"false" { return TOKEN_BOOLEAN_LITERAL; }

'([^\\]|\\.)' { return TOKEN_CHAR_LITERAL; }

\"(([^"\n]|([^\\]\\\"))*)\"    { return TOKEN_STRING_LITERAL; }             

{KEYWORD}   { return TOKEN_KEYWORD; }

{GROUP_OP} { return TOKEN_GROUP_OP; }

{COMP_OP} { return TOKEN_COMP_OP; }

{ARITH_OP} { return TOKEN_ARITH_OP; }

{LOGIC_OP}  { return TOKEN_LOGIC_OP; }

{LANGUAGE_SPEC} { return TOKEN_LANGUAGE_SPEC; }

{ID}        { return TOKEN_INDENT; }

\/\*([^*]*|\*+[^/])*\*\/    /* eat up comments */

\/\/.*  /* eat up inline comments */

[ \t\n\r]+          /* eat up whitespace */

<<EOF>> { exit(0);}
.           {
                fprintf( stderr, "scann error: Unrecognized character: %s\n", yytext );
                exit(1);
            }
%%


int main( int argc, char **argv )
 {
    int opt;
    static struct option long_options[] = {
	{"scan", 1, 0, 's'}
    };
    int long_index = 0;
    opt = getopt_long_only (argc, argv, "",
		long_options, &long_index);
    switch (opt) {
	case 's':
		yyin = fopen( optarg, "r" );
		int i;
 		while (1) {
       			token_t t = yylex();
        		if (!yyin) break;
        		printf("%s\n", token_string(t, yytext, yyleng));
    		}
		break;
	default: 
		exit(1);
     }
 }
 
