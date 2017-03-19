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
    FUNC = 258,
    RETURN = 259,
    MOD = 260,
    AND = 261,
    OR = 262,
    NOT = 263,
    CONST = 264,
    TRUE = 265,
    FALSE = 266,
    INT = 267,
    BOOL = 268,
    DECL = 269,
    ENDDECL = 270,
    ENDOFFILE = 271,
    MAIN = 272,
    READ = 273,
    WRITE = 274,
    IF = 275,
    THEN = 276,
    ELSE = 277,
    ENDIF = 278,
    WHILE = 279,
    DO = 280,
    ENDWHILE = 281,
    END = 282,
    NUM = 283,
    ID = 284,
    PLUS = 285,
    MINUS = 286,
    MUL = 287,
    DIV = 288,
    ASSGN = 289,
    LT = 290,
    LE = 291,
    GT = 292,
    GE = 293,
    EQ = 294,
    NEQ = 295
  };
#endif
/* Tokens.  */
#define FUNC 258
#define RETURN 259
#define MOD 260
#define AND 261
#define OR 262
#define NOT 263
#define CONST 264
#define TRUE 265
#define FALSE 266
#define INT 267
#define BOOL 268
#define DECL 269
#define ENDDECL 270
#define ENDOFFILE 271
#define MAIN 272
#define READ 273
#define WRITE 274
#define IF 275
#define THEN 276
#define ELSE 277
#define ENDIF 278
#define WHILE 279
#define DO 280
#define ENDWHILE 281
#define END 282
#define NUM 283
#define ID 284
#define PLUS 285
#define MINUS 286
#define MUL 287
#define DIV 288
#define ASSGN 289
#define LT 290
#define LE 291
#define GT 292
#define GE 293
#define EQ 294
#define NEQ 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
