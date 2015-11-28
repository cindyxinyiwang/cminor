/*
Main program of calculator example.
Simply invoke the parser generated by bison, and then display the output.
*/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "decl.h"
#include "expr.h"
#include "stmt.h"
#include "symbol.h"
#include "type.h"
#include "param_list.h"
#include "scope.h"
#include "register.h"

/* Clunky: Declare the parse function generated from parser.bison */
extern int yyparse();

extern FILE* yyin;

/* Clunky: Declare the result of the parser from parser.bison */
extern struct decl * parser_result;



int main( int argc, char *argv[] )
{
    decl_has_error = 0;
    decl_cur_label = 0;
    expr_string_count = 0;


    int i = 0;
    for (i = 0; i < 16; i++) 
    {
      if (i < 8)
        reg_taken[i] = 1;
      else 
        reg_taken[i] = 0;
    }

    int opt;
    static struct option long_options[] = {
	       {"print", 1, 0, 'p'},
        {"resolve", 1, 0, 's'},
        {"typecheck", 1, 0, 't'},
        {"codegen", 1, 0, 'c'}
    };
    int long_index = 0;
    opt = getopt_long_only (argc, argv, "",
		long_options, &long_index);

    char *out_name;
    FILE *out_file;

    switch (opt) {
		case 'p':
			yyin = fopen( optarg, "r" );
      if (!yyin) {
        printf("file not opened!\n");
        exit(1);
      }
 			do {
 				if (yyparse() == 0 && yyin == 0) {
 					decl_print(parser_result, 0);
 					exit(0);
 				} else {
 					exit(1);
 				}
 			} while (1);
  		break;
    case 's':
      yyin = fopen( optarg, "r" );
      if (!yyin) {
          printf("file not opened!\n");
          exit(1);
      }
      do {
        if (yyparse() == 0 && yyin == 0) {
          decl_resolve(parser_result, SYMBOL_GLOBAL);
          exit(0);
        } else {
          exit(1);
        }
      } while (1);
      break;
    case 't':
       yyin = fopen( optarg, "r" );
      if (!yyin) {
          printf("file not opened!\n");
          exit(1);
      }
      do {
        if (yyparse() == 0 && yyin == 0) {
          decl_resolve(parser_result, SYMBOL_GLOBAL);
          decl_typecheck(parser_result);
          if (decl_has_error) {
            exit(1);
          } else {
            exit(0);           
          }
        } else {
          exit(1);
        }
      } while (1);
      break; 
    case 'c':
      out_name = malloc(sizeof(char) * (strlen(optarg)+1));
      strcpy(out_name, optarg);
      out_name[strlen(optarg)-7] = '.';
      out_name[strlen(optarg)-6] = 's';
      out_name[strlen(optarg)-5] = '\0';

      yyin = fopen( optarg, "r" );
      out_file = fopen(out_name, "wb+");
      if (!yyin) {
          printf("file not opened!\n");
          exit(1);
      }
      do {
        if (yyparse() == 0 && yyin == 0) {
          decl_resolve(parser_result, SYMBOL_GLOBAL);
          decl_typecheck(parser_result);
          decl_codegen(parser_result, out_file);
          // append the string values
          int cur_str_label = 0;
          fprintf(out_file, ".data\n");
          while (expr_string_literals) {
            fprintf(out_file, ".LS%d:\n", cur_str_label);
            fprintf(out_file, ".string %s\n", expr_string_literals->string_literal);
            cur_str_label++;
            expr_string_literals = expr_string_literals->next;
          }

          exit(0);
        } else {
          exit(1);
        }
      } while (1);
      break;         
		default: 
			exit(1);
     }
}

