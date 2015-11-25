#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

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