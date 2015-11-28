/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_ID = 258,
     TOKEN_INTEGER = 259,
     TOKEN_CHAR = 260,
     TOKEN_STRING = 261,
     TOKEN_ADD = 262,
     TOKEN_SUBTRACT = 263,
     TOKEN_MULTIPLY = 264,
     TOKEN_DIVIDE = 265,
     TOKEN_ASSIGN = 266,
     TOKEN_MODULO = 267,
     TOKEN_EXPO = 268,
     TOKEN_POST_INCREASE = 269,
     TOKEN_POST_DECREASE = 270,
     TOKEN_NOT = 271,
     TOKEN_LT = 272,
     TOKEN_GT = 273,
     TOKEN_LE = 274,
     TOKEN_GE = 275,
     TOKEN_EQ = 276,
     TOKEN_NEQ = 277,
     TOKEN_AND = 278,
     TOKEN_OR = 279,
     TOKEN_LPAREN = 280,
     TOKEN_RPAREN = 281,
     TOKEN_LSQBRAC = 282,
     TOKEN_RSQBRAC = 283,
     TOKEN_LBRAC = 284,
     TOKEN_RBRAC = 285,
     TOKEN_COLON = 286,
     TOKEN_COMA = 287,
     TOKEN_SEMI = 288,
     TOKEN_KEYWORD_INTEGER = 289,
     TOKEN_KEYWORD_BOOLEAN = 290,
     TOKEN_KEYWORD_CHAR = 291,
     TOKEN_KEYWORD_STRING = 292,
     TOKEN_KEYWORD_ARRAY = 293,
     TOKEN_KEYWORD_TRUE = 294,
     TOKEN_KEYWORD_FALSE = 295,
     TOKEN_KEYWORD_VOID = 296,
     TOKEN_KEYWORD_FUNCTION = 297,
     TOKEN_KEYWORD_IF = 298,
     TOKEN_KEYWORD_ELSE = 299,
     TOKEN_KEYWORD_FOR = 300,
     TOKEN_KEYWORD_PRINT = 301,
     TOKEN_KEYWORD_RETURN = 302,
     TOKEN_END = 303
   };
#endif
/* Tokens.  */
#define TOKEN_ID 258
#define TOKEN_INTEGER 259
#define TOKEN_CHAR 260
#define TOKEN_STRING 261
#define TOKEN_ADD 262
#define TOKEN_SUBTRACT 263
#define TOKEN_MULTIPLY 264
#define TOKEN_DIVIDE 265
#define TOKEN_ASSIGN 266
#define TOKEN_MODULO 267
#define TOKEN_EXPO 268
#define TOKEN_POST_INCREASE 269
#define TOKEN_POST_DECREASE 270
#define TOKEN_NOT 271
#define TOKEN_LT 272
#define TOKEN_GT 273
#define TOKEN_LE 274
#define TOKEN_GE 275
#define TOKEN_EQ 276
#define TOKEN_NEQ 277
#define TOKEN_AND 278
#define TOKEN_OR 279
#define TOKEN_LPAREN 280
#define TOKEN_RPAREN 281
#define TOKEN_LSQBRAC 282
#define TOKEN_RSQBRAC 283
#define TOKEN_LBRAC 284
#define TOKEN_RBRAC 285
#define TOKEN_COLON 286
#define TOKEN_COMA 287
#define TOKEN_SEMI 288
#define TOKEN_KEYWORD_INTEGER 289
#define TOKEN_KEYWORD_BOOLEAN 290
#define TOKEN_KEYWORD_CHAR 291
#define TOKEN_KEYWORD_STRING 292
#define TOKEN_KEYWORD_ARRAY 293
#define TOKEN_KEYWORD_TRUE 294
#define TOKEN_KEYWORD_FALSE 295
#define TOKEN_KEYWORD_VOID 296
#define TOKEN_KEYWORD_FUNCTION 297
#define TOKEN_KEYWORD_IF 298
#define TOKEN_KEYWORD_ELSE 299
#define TOKEN_KEYWORD_FOR 300
#define TOKEN_KEYWORD_PRINT 301
#define TOKEN_KEYWORD_RETURN 302
#define TOKEN_END 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 63 "parser.bison"
{
	struct decl* decl_ptr;
	struct type* type_ptr; 
	struct expr* expr_ptr;
	struct stmt* stmt_ptr;
	struct param_list* param_list_ptr;
	char* char_ptr;
}
/* Line 1529 of yacc.c.  */
#line 154 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

