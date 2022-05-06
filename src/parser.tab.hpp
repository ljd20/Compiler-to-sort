/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"

  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //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

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 64 "src/parser.tab.hpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_TIMES = 258,
    T_DIVIDE = 259,
    T_PLUS = 260,
    T_MINUS = 261,
    T_EXPONENT = 262,
    T_AND = 263,
    T_OR = 264,
    T_NOT = 265,
    T_DOUBLEPLUS = 266,
    T_DOUBLEMINUS = 267,
    T_LBRACKET = 268,
    T_RBRACKET = 269,
    T_LCURLY = 270,
    T_RCURLY = 271,
    T_LSQUARE = 272,
    T_RSQUARE = 273,
    T_SEMI = 274,
    T_MOD = 275,
    T_NUMBER = 276,
    T_VARIABLE = 277,
    T_BITAND = 278,
    T_BITOR = 279,
    T_BITXOR = 280,
    T_BITNOT = 281,
    T_LEFTSHIFT = 282,
    T_RIGHTSHIFT = 283,
    T_INT = 284,
    T_VOID = 285,
    T_DOUBLEEQUAL = 286,
    T_NOTEQUAL = 287,
    T_LESSEQUAL = 288,
    T_GREATEQUAL = 289,
    T_IF = 290,
    T_ELSE = 291,
    T_WHILE = 292,
    T_GREAT = 293,
    T_LESS = 294,
    T_EQUAL = 295,
    T_PLUSASSIGN = 296,
    T_MINUSASSIGN = 297,
    T_MULTASSIGN = 298,
    T_DIVASSIGN = 299,
    T_MODASSIGN = 300,
    T_LEFTASSIGN = 301,
    T_RIGHTASSIGN = 302,
    T_ANDASSIGN = 303,
    T_XORASSIGN = 304,
    T_ORASSIGN = 305,
    T_COMMA = 306,
    T_GOTO = 307,
    T_CONTINUE = 308,
    T_BREAK = 309,
    T_RETURN = 310,
    T_DO = 311,
    T_FOR = 312,
    T_SWITCH = 313,
    T_COLON = 314,
    T_CASE = 315,
    T_DEFAULT = 316,
    T_ELLIPSIS = 317,
    T_CONST = 318,
    T_CHAR = 319,
    T_SHORT = 320,
    T_LONG = 321,
    T_DOUBLE = 322,
    T_SIGNED = 323,
    T_UNSIGNED = 324,
    T_TYPENAME = 325,
    T_STOP = 326,
    T_STRING_LITERAL = 327,
    T_IDENTIFIER = 328,
    T_VOLATILE = 329,
    T_STRUCT = 330,
    T_UNION = 331,
    T_TYPEDEF = 332,
    T_EXTERN = 333,
    T_STATIC = 334,
    T_AUTO = 335,
    T_REGISTER = 336,
    T_QUESTION = 337,
    T_SIZEOF = 338,
    T_POINTER = 339
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "src/parser.y"

  const Node *expr;
  double number;
  std::string *string;
  

#line 167 "src/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
