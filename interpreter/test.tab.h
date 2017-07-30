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
     START = 258,
     PRINT = 259,
     GET = 260,
     LINK = 261,
     TABLE = 262,
     ROW = 263,
     COL = 264,
     DIV = 265,
     NUMBER = 266,
     STRING = 267,
     BUTTON = 268,
     EDIT = 269,
     TEXT = 270,
     LPAREN = 271,
     RPAREN = 272,
     LBRAC = 273,
     RBRAC = 274,
     QUOTE = 275,
     DOTS = 276,
     COLON = 277,
     SEMICOLON = 278
   };
#endif
/* Tokens.  */
#define START 258
#define PRINT 259
#define GET 260
#define LINK 261
#define TABLE 262
#define ROW 263
#define COL 264
#define DIV 265
#define NUMBER 266
#define STRING 267
#define BUTTON 268
#define EDIT 269
#define TEXT 270
#define LPAREN 271
#define RPAREN 272
#define LBRAC 273
#define RBRAC 274
#define QUOTE 275
#define DOTS 276
#define COLON 277
#define SEMICOLON 278




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

