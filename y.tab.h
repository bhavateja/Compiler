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
    INIT = 258,
    TYPEI = 259,
    ENDTYPEI = 260,
    FREE = 261,
    ALLOC = 262,
    EXIT = 263,
    FIELD = 264,
    NULL_NODE = 265,
    BEGINNING = 266,
    END = 267,
    FUNC = 268,
    RETURN = 269,
    MOD = 270,
    AND = 271,
    OR = 272,
    NOT = 273,
    CONST = 274,
    TRUE = 275,
    FALSE = 276,
    INT = 277,
    BOOL = 278,
    DECL = 279,
    ENDDECL = 280,
    ENDOFFILE = 281,
    MAIN = 282,
    READ = 283,
    WRITE = 284,
    IF = 285,
    THEN = 286,
    ELSE = 287,
    ENDIF = 288,
    WHILE = 289,
    DO = 290,
    ENDWHILE = 291,
    NUM = 292,
    ID = 293,
    PLUS = 294,
    MINUS = 295,
    MUL = 296,
    DIV = 297,
    ASSGN = 298,
    LT = 299,
    LE = 300,
    GT = 301,
    GE = 302,
    EQ = 303,
    NEQ = 304
  };
#endif
/* Tokens.  */
#define INIT 258
#define TYPEI 259
#define ENDTYPEI 260
#define FREE 261
#define ALLOC 262
#define EXIT 263
#define FIELD 264
#define NULL_NODE 265
#define BEGINNING 266
#define END 267
#define FUNC 268
#define RETURN 269
#define MOD 270
#define AND 271
#define OR 272
#define NOT 273
#define CONST 274
#define TRUE 275
#define FALSE 276
#define INT 277
#define BOOL 278
#define DECL 279
#define ENDDECL 280
#define ENDOFFILE 281
#define MAIN 282
#define READ 283
#define WRITE 284
#define IF 285
#define THEN 286
#define ELSE 287
#define ENDIF 288
#define WHILE 289
#define DO 290
#define ENDWHILE 291
#define NUM 292
#define ID 293
#define PLUS 294
#define MINUS 295
#define MUL 296
#define DIV 297
#define ASSGN 298
#define LT 299
#define LE 300
#define GT 301
#define GE 302
#define EQ 303
#define NEQ 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
