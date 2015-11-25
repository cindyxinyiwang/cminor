#include "token.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const char *token_string(token_t t, char* yytext, int yyleng) {
	switch (t) {
		case TOKEN_INDENT:
            if (strlen(yytext) > 256) {
                // the identifier has more than 256 characters
                fprintf( stderr, "scann error: identifier %s cannot have more than 256 characters\n", yytext );
                exit(1);
            }
			return "IDENTIFIER";
		case TOKEN_INTEGER_LITERAL:
        {
            /*
            int overflow = 0;
            if (strlen(yytext) > 19) {
                // the number has more than 19 digits, which is for sure overflow
                overflow = 1;
            } else if (strlen(yytext) == 19) {
                // check if greater than 9223372036854775807
                int checks[19] = {9,2,2,3,3,7,2,0,3,6,8,5,4,7,7,5,8,0,7};
                for (int i = 0; i < 19; i++) {
                    if (checks[i] < (yytext[i] - '0')) {
                        overflow = 1;
                        break;
                    }
                }
            }
            if (overflow) {
                // overflow
                fprintf( stderr, "scann error: number %s excceeds the max value 9223372036854775807\n", yytext );
                exit(1);
            } */
			return "INTEGER";
        }
		case TOKEN_BOOLEAN_LITERAL:
			return "BOOLEAN";
		case TOKEN_CHAR_LITERAL:
			{
				char *strTemp = "CHAR_LITERAL:  ";
				char *val = (char*)malloc(sizeof(char)*(strlen(strTemp)+1));
				strcpy(val, strTemp);
				char c;
                if (yyleng > 3) {
                    switch (yytext[2]) {
                            case 'n':
                                c = '\n';
                                break;
                            case '0':
                                c = '\0';
                                break;
                            default:
                                c = yytext[2];
                                break;
                        } 
                } else{
                    c = yytext[1];
                }
                val[strlen(val) - 1] = c;
            	return val;
        	}
        case TOKEN_STRING_LITERAL:
        	{
        		char newStr[yyleng];
                int curPos = 0;
                int i = 1;
                for (i = 1; i < yyleng-1; i++) {
                    if (yytext[i] == '\\') {
                        switch (yytext[i+1]) {
                            case 'n':
                                newStr[curPos] = '\n';
                                break;
                            case '0':
                                newStr[curPos] = '\0';
                                break;
                            default:
                                newStr[curPos] = yytext[i+1];
                                break;
                        } 
                        i++;
                    } else {
                        newStr[curPos] = yytext[i];
                    }
                    curPos++;
                }
                newStr[curPos] = '\0';
                if (strlen(newStr) > 255) {
                    // string with more than 256 chars
                    fprintf( stderr, "scann error: illegal string(cannot excceed 256 chars): %s\n", yytext );
                    exit(1);
                }
                // copy string blobs into return value
                char *strTemp = "STRING_LITERAL: ";
				char *val = (char*)malloc(sizeof(char)*(strlen(strTemp)+curPos+1));
				strcpy(val, strTemp);
				// copy retrived string into return value
				// pointer to the start of the string literal position
				char *valStart = val + strlen(strTemp);
				strcpy(valStart, newStr);
                return val;
        	}
        case TOKEN_KEYWORD:
        	{
        		char *strTemp = "KEYWORD: ";
				char *val = (char*)malloc(sizeof(char)*(strlen(strTemp)+yyleng+1));
				strcpy(val, strTemp);
				// get the pointer to start of retrived keyword and copy it in
				char *valStart = val + strlen(strTemp);
				strcpy(valStart, yytext);
				return val;
        	}
        case TOKEN_GROUP_OP:
        	{
        		char *strTemp = "GROUP_OPERATOR: ";
				char *val = (char*)malloc(sizeof(char)*(strlen(strTemp)+yyleng+1));
				strcpy(val, strTemp);
				// get the pointer to start of retrived keyword and copy it in
				char *valStart = val + strlen(strTemp);
				strcpy(valStart, yytext);
				return val;
        	} 
        case TOKEN_COMP_OP:
	        {
	        	if (yytext[0] == '=') {
	        		return "EQ";
	        	} else if (yytext[0] == '!') {
	        		return "NE";
	        	} else if (yytext[0] == '>') {
	        		if (yyleng > 1) {
	        			return "GE";
	        		} else {
	        			return "GT";
	        		}
	        	} else {
	        		if (yyleng > 1) {
	        			return "SE";
	        		} else {
	        			return "ST";
	        		}
	        	}
	        }
        case TOKEN_ARITH_OP:
        	{
        		char *strTemp = "ARITHMATIC_OPERATOR: ";
				char *val = (char*)malloc(sizeof(char)*(strlen(strTemp)+yyleng+1));
				strcpy(val, strTemp);
				// get the pointer to start of retrived keyword and copy it in
				char *valStart = val + strlen(strTemp);
				strcpy(valStart, yytext);
				return val;        		
        	}
        case TOKEN_LOGIC_OP:
    	    {
    	    	if (yytext[0] == '&') {
    	    		return "LOGIC_OPERATOR: AND";
    	    	} else {
    	    		return "LOGIC_OPERATOR: OR";
    	    	}
    	    }
    	case TOKEN_LANGUAGE_SPEC:
    		return yytext;     
		default:
			return "unrecognized";
	}
}
