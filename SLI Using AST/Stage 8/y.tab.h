/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MOD = 258,
    AND = 259,
    OR = 260,
    NOT = 261,
    CONST = 262,
    TRUE = 263,
    FALSE = 264,
    INT = 265,
    BOOL = 266,
    DECL = 267,
    ENDDECL = 268,
    ENDOFFILE = 269,
    MAIN = 270,
    READ = 271,
    WRITE = 272,
    IF = 273,
    THEN = 274,
    ELSE = 275,
    ENDIF = 276,
    WHILE = 277,
    DO = 278,
    ENDWHILE = 279,
    END = 280,
    NUM = 281,
    ID = 282,
    PLUS = 283,
    MINUS = 284,
    MUL = 285,
    DIV = 286,
    ASSGN = 287,
    LT = 288,
    LE = 289,
    GT = 290,
    GE = 291,
    EQ = 292,
    NEQ = 293
  };
#endif
/* Tokens.  */
#define MOD 258
#define AND 259
#define OR 260
#define NOT 261
#define CONST 262
#define TRUE 263
#define FALSE 264
#define INT 265
#define BOOL 266
#define DECL 267
#define ENDDECL 268
#define ENDOFFILE 269
#define MAIN 270
#define READ 271
#define WRITE 272
#define IF 273
#define THEN 274
#define ELSE 275
#define ENDIF 276
#define WHILE 277
#define DO 278
#define ENDWHILE 279
#define END 280
#define NUM 281
#define ID 282
#define PLUS 283
#define MINUS 284
#define MUL 285
#define DIV 286
#define ASSGN 287
#define LT 288
#define LE 289
#define GT 290
#define GE 291
#define EQ 292
#define NEQ 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
