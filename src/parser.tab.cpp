/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 127 "src/parser.tab.cpp"

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
  

#line 230 "src/parser.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  207
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  350

#define YYUNDEFTOK  2
#define YYMAXUTOK   339


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    58,    59,    60,    61,    72,    73,    74,
      75,    76,    79,    80,    81,    82,    84,    85,    86,    89,
      90,    93,    94,    97,    98,   101,   102,   103,   104,   107,
     108,   109,   112,   113,   114,   115,   116,   117,   120,   121,
     124,   125,   126,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   140,   141,   142,   145,   146,   149,   150,   153,
     154,   155,   158,   159,   162,   163,   166,   167,   170,   171,
     172,   173,   176,   177,   178,   179,   180,   181,   182,   185,
     186,   189,   190,   193,   194,   197,   198,   201,   202,   203,
     206,   207,   208,   211,   212,   215,   216,   217,   218,   221,
     224,   225,   228,   229,   232,   233,   234,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   250,   251,
     252,   253,   254,   257,   258,   261,   262,   265,   266,   267,
     268,   269,   270,   273,   274,   277,   281,   282,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   298,
     299,   302,   303,   306,   307,   310,   311,   314,   315,   318,
     319,   322,   323,   326,   327,   328,   331,   332,   333,   334,
     335,   338,   339,   340,   343,   344,   345,   348,   349,   350,
     351,   354,   355,   358,   359,   360,   361,   362,   365,   366,
     367,   368,   369,   370,   373,   374,   377,   378,   379,   380,
     381,   382,   383,   384,   387,   388,   389,   390
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_TIMES", "T_DIVIDE", "T_PLUS",
  "T_MINUS", "T_EXPONENT", "T_AND", "T_OR", "T_NOT", "T_DOUBLEPLUS",
  "T_DOUBLEMINUS", "T_LBRACKET", "T_RBRACKET", "T_LCURLY", "T_RCURLY",
  "T_LSQUARE", "T_RSQUARE", "T_SEMI", "T_MOD", "T_NUMBER", "T_VARIABLE",
  "T_BITAND", "T_BITOR", "T_BITXOR", "T_BITNOT", "T_LEFTSHIFT",
  "T_RIGHTSHIFT", "T_INT", "T_VOID", "T_DOUBLEEQUAL", "T_NOTEQUAL",
  "T_LESSEQUAL", "T_GREATEQUAL", "T_IF", "T_ELSE", "T_WHILE", "T_GREAT",
  "T_LESS", "T_EQUAL", "T_PLUSASSIGN", "T_MINUSASSIGN", "T_MULTASSIGN",
  "T_DIVASSIGN", "T_MODASSIGN", "T_LEFTASSIGN", "T_RIGHTASSIGN",
  "T_ANDASSIGN", "T_XORASSIGN", "T_ORASSIGN", "T_COMMA", "T_GOTO",
  "T_CONTINUE", "T_BREAK", "T_RETURN", "T_DO", "T_FOR", "T_SWITCH",
  "T_COLON", "T_CASE", "T_DEFAULT", "T_ELLIPSIS", "T_CONST", "T_CHAR",
  "T_SHORT", "T_LONG", "T_DOUBLE", "T_SIGNED", "T_UNSIGNED", "T_TYPENAME",
  "T_STOP", "T_STRING_LITERAL", "T_IDENTIFIER", "T_VOLATILE", "T_STRUCT",
  "T_UNION", "T_TYPEDEF", "T_EXTERN", "T_STATIC", "T_AUTO", "T_REGISTER",
  "T_QUESTION", "T_SIZEOF", "T_POINTER", "$accept", "ROOT", "FUNCTION_DEF",
  "JUMP", "ITERATION", "SELECTION", "EXPRESSION_STATEMENT", "STATEMENT_LS",
  "DECLARATION_LS", "COMPOUND", "LABELED", "STATEMENT", "INITIALIZER_LS",
  "INITIALIZER", "DIRECT_ABSTRACT_DECLARATOR", "ABSTRACT_DECLARATOR",
  "TYPE_NAME", "IDENTIFIER_LS", "PARAMETER_DECLARATION", "PARAMETER_LS",
  "PARAMETER_TYPE_LS", "TYPE_QUALIFIER_LS", "POINTER", "DIRECT_DECLARATOR",
  "DECLARATOR", "TYPE_QUALFIIER", "ENUM", "ENUM_LS", "ENUM_SPECIFIER",
  "STRUCT_DECLARATOR", "STRUCT_DELCLARATOR_LS", "SPECIFIER_QUALIFIER_LS",
  "STRUCT_DECLARATION", "STRUCT_DECLARATION_LS", "STRUCT_OR_UNION",
  "STRUCT_OR_UNION_SPECIFIER", "TYPE_SPECIFIER", "STORAGE_CLASS",
  "INIT_DECLARATOR", "INIT_DECLARATOR_LS", "DECLARATION_SPECIFIER",
  "DECLARATION", "CONSTANT", "EXPRESSION", "ASSIGN_OPERATOR", "ASSIGNMENT",
  "CONDITIONAL", "LOGICAL_OR", "LOGICAL_AND", "INCLUSIVE_OR",
  "EXCLUSIVE_OR", "AND_EXP", "EQUALITY", "RELATIONAL", "SHIFTING",
  "ADDITION", "MULTIPLICATION", "CASTING", "UNARY_OPERATOR", "UNARY",
  "ARGUMENT_EXPRESSION_LS", "POST_EXPRESSION", "PRIMARY", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339
};
# endif

#define YYPACT_NINF (-257)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     977,    20,    42,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,    12,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,   150,  -257,    68,    46,  1090,  1187,    -3,  -257,
      13,  -257,  1187,  1187,    42,    20,  -257,  -257,  -257,    62,
     818,  -257,    46,  1048,   676,   280,    12,  1090,  -257,    18,
    -257,  -257,   132,   197,  1019,   202,  -257,  -257,  1090,  -257,
    -257,  -257,  -257,  -257,  -257,   837,   837,   600,  -257,  -257,
    -257,  -257,  -257,   193,  -257,  -257,   138,   222,   198,   199,
     216,   214,   195,   220,   253,    76,  -257,   818,  -257,    30,
    -257,  -257,   136,    11,  -257,   203,   242,    16,  -257,   249,
    -257,  -257,   247,   264,   207,   262,   265,   701,   564,   274,
     275,   818,   230,   859,   129,  -257,  -257,  -257,  -257,   438,
     359,  -257,  -257,  -257,    37,  -257,  -257,   278,  -257,  -257,
    -257,   250,  -257,   175,  -257,    92,   132,  1019,  1000,  -257,
    1122,  1019,  1019,  1090,  -257,   818,  -257,  -257,   136,   283,
      90,    24,  1019,  -257,   818,   818,   818,   818,   818,   818,
     818,   818,   818,   818,   818,   818,   818,   818,   818,   818,
     818,   818,   818,  -257,  -257,  -257,   395,   818,   221,   225,
    -257,   227,  1164,  -257,   889,   720,   187,  -257,     5,  -257,
    -257,   818,   818,   282,  -257,  -257,  -257,   176,   243,   268,
     739,   818,   248,   564,   564,  -257,  -257,  -257,   501,  -257,
     818,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,   818,   764,  -257,    42,  -257,   132,   162,  -257,
     818,   252,  -257,   289,  1218,  -257,  -257,  -257,  1145,  -257,
     818,   958,  -257,   194,  -257,   298,   130,   198,   305,   199,
     216,   214,   195,   195,   220,   220,   220,   220,   253,   253,
      76,    76,  -257,  -257,  -257,  -257,  -257,    44,    14,  -257,
    -257,  -257,  -257,  -257,  -257,   300,   302,  -257,   311,  1067,
     783,   187,   123,   128,  -257,  -257,   317,   739,   152,   564,
    -257,  -257,  -257,  -257,  -257,   764,  -257,  -257,  -257,  -257,
    -257,  -257,   818,  -257,   159,  -257,  -257,  -257,   818,  -257,
     818,  -257,  -257,  -257,  -257,  -257,   325,  -257,   313,   564,
     564,   818,   802,   564,  -257,   164,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,   306,  -257,   157,   564,   163,  -257,  -257,
     628,   564,   332,  -257,   564,  -257,  -257,  -257,  -257,  -257
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    68,     0,   110,   107,    81,   108,   109,   111,   112,
     113,   114,   115,    72,    82,   102,   103,   118,   119,   120,
     121,   122,     0,     2,     0,    80,     0,   131,     0,   117,
       0,   116,   129,   127,     0,    70,    69,    66,    72,     0,
       0,     1,    79,     0,     0,     0,    83,     0,     6,     0,
      23,   132,     0,    89,     0,   106,   130,   128,     0,    71,
      67,    73,   187,   186,   185,     0,     0,     0,   183,   184,
     206,   207,   204,     0,    84,   135,   151,   153,   155,   157,
     159,   161,   163,   166,   171,   174,   177,     0,   181,   188,
     196,    76,    57,     0,    62,    64,     0,    60,    75,     0,
      25,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   206,   204,    37,    36,    35,    34,     0,
       0,    33,    32,    21,     0,   136,   149,   181,     5,    24,
     133,   123,   125,     0,    85,     0,     0,    98,     0,   100,
       0,    96,     0,     0,     4,     0,   189,   190,   204,     0,
      55,     0,     0,   192,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   198,   199,     0,     0,     0,     0,
      78,     0,     0,    77,     0,     0,    53,    61,    52,    59,
      74,     0,     0,     0,     8,     9,    10,     0,   204,     0,
       0,     0,     0,     0,     0,    26,    22,    27,     0,    20,
       0,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,     0,   134,     0,    87,     0,     0,    97,
       0,    90,    93,     0,     0,   105,   101,    95,     0,     3,
       0,     0,    56,    52,   205,     0,     0,   156,   154,   158,
     160,   162,   164,   165,   169,   170,   168,   167,   172,   173,
     175,   176,   178,   179,   180,   197,   194,     0,     0,   203,
     200,    58,    65,    63,    48,     0,     0,    44,     0,     0,
       0,    54,     0,     0,     7,    11,     0,     0,     0,     0,
      31,    29,    28,   137,   150,     0,   124,    40,   126,    86,
      88,    91,     0,    99,     0,   104,   182,   193,     0,   202,
       0,   201,    43,    49,    45,    50,     0,    46,     0,     0,
       0,     0,     0,     0,    30,     0,    38,    92,    94,   152,
     195,    51,    47,    16,    12,     0,     0,     0,    18,    41,
       0,     0,     0,    14,     0,    42,    39,    17,    13,    15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -257,  -257,  -257,  -257,  -257,  -257,  -183,   246,   165,    27,
    -257,   -68,  -257,  -256,  -175,   -37,   215,  -257,   186,  -257,
     -36,  -257,     9,   -15,     0,    15,   -44,   233,  -257,    69,
    -257,    45,  -129,   -81,  -257,  -257,    23,  -257,   151,  -257,
       3,   -33,   -40,   -43,  -257,  -156,   -38,  -257,   223,   226,
     229,   219,   224,   105,    73,   108,   103,   -72,   307,   -39,
    -257,  -257,  -257
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,   115,   116,   117,   118,   119,    47,   121,
     122,   123,   325,   296,   186,   275,   149,    93,    94,    95,
     276,    35,    24,    25,    39,    27,    28,   135,    29,   232,
     233,   138,   139,   140,    30,    31,    32,    33,   132,   133,
      49,    50,    74,   124,   222,   125,   126,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   127,
     267,    89,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    88,    75,    34,    99,    88,    75,    96,   134,    42,
      36,   236,    52,   281,   129,   173,    37,   287,   184,     1,
     266,     1,   185,     1,   151,   180,   146,   147,    54,   184,
      51,     2,   311,   185,    58,    56,    57,   130,   244,   326,
     199,   174,   175,   176,    59,     1,    97,   177,    88,   131,
      60,   206,    40,    48,   293,     2,   209,   234,   309,    43,
     187,   238,   181,    44,   197,   210,   294,   297,   281,   137,
      53,   202,    88,    75,   128,   210,    61,   141,    38,   170,
     171,     2,   137,     5,   346,   144,    55,   129,   210,    38,
     141,    38,   134,     1,    14,   310,   172,   189,   262,   263,
     264,   178,   151,   241,   322,   236,   188,   185,   226,   236,
     129,   246,   150,   242,   179,    38,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,   268,   290,   291,   319,   231,   297,
     206,    38,   320,   227,   -83,   278,    88,    75,   282,   283,
      41,   -83,   137,   137,   330,   137,   137,   137,   288,   243,
     141,   141,     1,   141,   141,   141,   323,   137,   306,    40,
     239,   342,     2,    42,   210,   141,    40,   344,   300,   210,
     339,   210,   229,   299,   297,    97,   237,    97,   204,   308,
     301,    88,    75,   188,   224,   285,    62,   150,    63,    64,
     279,    88,   -83,   210,   280,    46,   152,   241,   210,   -83,
     120,   185,   136,   227,   210,   340,    68,   142,   230,    69,
     154,   324,   157,   143,   158,   131,   225,   210,   162,   163,
     155,   156,    38,   164,   165,   254,   255,   256,   257,   159,
     318,    88,    75,   316,    97,   160,   161,   166,   167,   137,
     243,   333,   334,   137,   182,   338,   183,   141,   168,   169,
     191,   141,   327,    88,    75,   252,   253,   190,   343,    88,
     329,   260,   261,   347,   258,   259,   349,   192,   335,   337,
     193,   194,    97,    62,   195,    63,    64,   200,   201,   203,
     223,    65,    66,    67,   269,    45,   100,   240,   270,   101,
     271,   284,   204,    68,   231,   286,    69,   289,   303,     3,
       4,   302,   307,   155,   312,   102,   313,   103,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   314,
     321,   332,   104,   105,   106,   107,   108,   109,   110,   331,
     111,   112,   341,   113,     6,     7,     8,     9,    10,    11,
      12,   348,    71,   114,    14,    15,    16,    17,    18,    19,
      20,    21,    62,    73,    63,    64,   208,   245,   273,   228,
      65,    66,    67,   328,    45,   207,   298,   250,   101,   248,
     153,   247,    68,   251,     0,    69,   249,     0,     3,     4,
       0,     0,     0,     0,   102,     0,   103,     0,    62,     0,
      63,    64,     0,     0,     0,     0,    65,    66,    67,   265,
       0,   104,   105,   106,   107,   108,   109,   110,    68,   111,
     112,    69,   113,     6,     7,     8,     9,    10,    11,    12,
       0,    71,   114,    14,    15,    16,    17,    18,    19,    20,
      21,    62,    73,    63,    64,     0,     0,     0,     0,    65,
      66,    67,     0,    45,   205,     0,     0,   101,    70,     0,
       0,    68,     0,     0,    69,     0,     0,    71,    72,     0,
       0,     0,     0,   102,     0,   103,     0,     0,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,     0,   111,   112,
       0,    70,     0,     0,    62,     0,    63,    64,     0,     0,
      71,   198,    65,    66,    67,     0,    45,   292,     0,     0,
     101,    73,     0,     0,    68,     0,     0,    69,     0,     0,
       0,     0,     0,     0,     0,     0,   102,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
       0,   111,   112,     0,    70,     0,     0,    62,     0,    63,
      64,     0,     0,    71,   198,    65,    66,    67,     0,    45,
       0,     0,     0,   101,    73,     0,     0,    68,     0,     0,
      69,     0,     0,     0,     0,     0,     0,     0,     0,   102,
       0,   103,     0,    62,     0,    63,    64,     0,     0,     0,
       0,    65,    66,    67,     0,     0,   104,   105,   106,   107,
     108,   109,   110,    68,   111,   112,    69,    70,     0,     3,
       4,    62,     0,    63,    64,     0,    71,   198,     0,    65,
      66,    67,     0,   295,   345,     0,     0,    73,     0,     0,
       0,    68,     0,     0,    69,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     6,     7,     8,     9,    10,    11,
      12,     0,    71,   148,    14,    15,    16,     0,     0,    62,
       0,    63,    64,    73,     0,     0,     0,    65,    66,    67,
       0,    70,     0,     0,    98,     0,     0,     0,     0,    68,
      71,    72,    69,     0,    62,     0,    63,    64,     0,     0,
       0,    73,    65,    66,    67,     0,     0,     0,     0,     0,
     196,     0,     0,    62,    68,    63,    64,    69,     0,     0,
       0,    65,    66,    67,     0,     0,     0,     0,   277,    70,
       0,     0,    62,    68,    63,    64,    69,     0,    71,    72,
      65,    66,    67,     0,     0,     0,     0,     0,   101,    73,
       0,     0,    68,     0,    70,    69,     0,    62,     0,    63,
      64,     0,     0,    71,    72,    65,    66,    67,     0,   295,
       0,     0,     0,    70,    73,     0,    62,    68,    63,    64,
      69,     0,    71,    72,    65,    66,    67,     0,     0,     0,
       0,   317,    70,    73,     0,    62,    68,    63,    64,    69,
       0,    71,    72,    65,    66,    67,   336,     0,     0,     0,
       0,    62,    73,    63,    64,    68,     0,    70,    69,    65,
      66,    67,     0,     0,     0,     0,    71,    72,     0,     0,
      62,    68,    63,    64,    69,     0,    70,    73,    65,    66,
     145,     0,     0,     0,     0,    71,    72,     0,     0,     0,
      68,     0,   -81,    69,     0,    70,    73,     0,     0,     0,
       0,     0,   -81,   -81,    71,    72,   -81,     0,   -81,     0,
       0,    70,     0,     0,     0,    73,     0,     0,   -81,   -81,
      71,    72,     1,     0,     0,     0,     0,     0,     0,     0,
      70,    73,   184,   274,     0,     0,   185,     0,     0,    71,
      72,     0,     0,     0,     0,     0,     0,     0,     3,     4,
      73,     0,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
       0,     0,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   241,   274,     0,     0,   185,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     3,     4,     0,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     3,     4,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,     3,
       4,    46,    14,    15,    16,    17,    18,    19,    20,    21,
       5,     6,     7,     8,     9,    10,    11,    12,     3,     4,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   230,
       0,     0,    91,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,    13,    14,    15,    16,     3,     4,     0,
       0,   315,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,    46,    14,    15,    16,     3,     4,     0,     0,
       0,     0,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,     3,
       4,    92,    14,    15,    16,    17,    18,    19,    20,    21,
       5,     6,     7,     8,     9,    10,    11,    12,   235,     0,
      46,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   305,     0,    46,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     3,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,     3,     4,    46,    14,    15,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,     3,     4,    46,    14,
      15,    16,     0,     0,     0,     0,   272,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,    46,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     3,     4,     0,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
      46,    14,    15,    16,    17,    18,    19,    20,    21,   304,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,    46,    14,    15,    16
};

static const yytype_int16 yycheck[] =
{
       0,    40,    40,     0,    44,    44,    44,    43,    52,    24,
       1,   140,    15,   188,    47,    87,     1,   200,    13,     3,
     176,     3,    17,     3,    67,    14,    65,    66,    15,    13,
      27,    13,    18,    17,    34,    32,    33,    19,    14,   295,
     108,    11,    12,    13,    35,     3,    43,    17,    87,    49,
      35,   119,    40,    26,   210,    13,    19,   138,    14,    13,
      97,   142,    51,    17,   107,    51,   222,   223,   243,    54,
      73,   111,   111,   111,    47,    51,    14,    54,    73,     3,
       4,    13,    67,    63,   340,    58,    73,   120,    51,    73,
      67,    73,   136,     3,    74,    51,    20,    97,   170,   171,
     172,    71,   145,    13,   287,   234,    97,    17,    16,   238,
     143,   154,    67,   150,    84,    73,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   177,   203,   204,    14,   138,   295,
     208,    73,    14,    51,    15,   185,   185,   185,   191,   192,
       0,    15,   137,   138,   310,   140,   141,   142,   201,   150,
     137,   138,     3,   140,   141,   142,    14,   152,   240,    40,
     143,    14,    13,   188,    51,   152,    40,    14,    16,    51,
      16,    51,   137,   227,   340,   182,   141,   184,    59,    59,
     230,   230,   230,   184,    19,    19,     3,   152,     5,     6,
      13,   240,    73,    51,    17,    73,    13,    13,    51,    73,
      45,    17,    15,    51,    51,    51,    23,    15,    59,    26,
      82,   289,    24,    58,    25,   225,    51,    51,    33,    34,
       8,     9,    73,    38,    39,   162,   163,   164,   165,    23,
     280,   280,   280,   279,   241,    31,    32,    27,    28,   234,
     241,   319,   320,   238,    51,   323,    14,   234,     5,     6,
      13,   238,   302,   302,   302,   160,   161,    18,   336,   308,
     308,   168,   169,   341,   166,   167,   344,    13,   321,   322,
      73,    19,   279,     3,    19,     5,     6,    13,    13,    59,
      40,    11,    12,    13,    73,    15,    16,    14,    73,    19,
      73,    19,    59,    23,   304,    37,    26,    59,    19,    29,
      30,    59,    14,     8,    14,    35,    14,    37,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    18,
      13,    18,    52,    53,    54,    55,    56,    57,    58,    14,
      60,    61,    36,    63,    64,    65,    66,    67,    68,    69,
      70,    19,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     3,    83,     5,     6,   120,   152,   182,   136,
      11,    12,    13,   304,    15,    16,   225,   158,    19,   156,
      73,   155,    23,   159,    -1,    26,   157,    -1,    29,    30,
      -1,    -1,    -1,    -1,    35,    -1,    37,    -1,     3,    -1,
       5,     6,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      -1,    52,    53,    54,    55,    56,    57,    58,    23,    60,
      61,    26,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     3,    83,     5,     6,    -1,    -1,    -1,    -1,    11,
      12,    13,    -1,    15,    16,    -1,    -1,    19,    63,    -1,
      -1,    23,    -1,    -1,    26,    -1,    -1,    72,    73,    -1,
      -1,    -1,    -1,    35,    -1,    37,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      -1,    63,    -1,    -1,     3,    -1,     5,     6,    -1,    -1,
      72,    73,    11,    12,    13,    -1,    15,    16,    -1,    -1,
      19,    83,    -1,    -1,    23,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    61,    -1,    63,    -1,    -1,     3,    -1,     5,
       6,    -1,    -1,    72,    73,    11,    12,    13,    -1,    15,
      -1,    -1,    -1,    19,    83,    -1,    -1,    23,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    37,    -1,     3,    -1,     5,     6,    -1,    -1,    -1,
      -1,    11,    12,    13,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,    23,    60,    61,    26,    63,    -1,    29,
      30,     3,    -1,     5,     6,    -1,    72,    73,    -1,    11,
      12,    13,    -1,    15,    16,    -1,    -1,    83,    -1,    -1,
      -1,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      70,    -1,    72,    73,    74,    75,    76,    -1,    -1,     3,
      -1,     5,     6,    83,    -1,    -1,    -1,    11,    12,    13,
      -1,    63,    -1,    -1,    18,    -1,    -1,    -1,    -1,    23,
      72,    73,    26,    -1,     3,    -1,     5,     6,    -1,    -1,
      -1,    83,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,     3,    23,     5,     6,    26,    -1,    -1,
      -1,    11,    12,    13,    -1,    -1,    -1,    -1,    18,    63,
      -1,    -1,     3,    23,     5,     6,    26,    -1,    72,    73,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    19,    83,
      -1,    -1,    23,    -1,    63,    26,    -1,     3,    -1,     5,
       6,    -1,    -1,    72,    73,    11,    12,    13,    -1,    15,
      -1,    -1,    -1,    63,    83,    -1,     3,    23,     5,     6,
      26,    -1,    72,    73,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    63,    83,    -1,     3,    23,     5,     6,    26,
      -1,    72,    73,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,     3,    83,     5,     6,    23,    -1,    63,    26,    11,
      12,    13,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,
       3,    23,     5,     6,    26,    -1,    63,    83,    11,    12,
      13,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,
      23,    -1,     3,    26,    -1,    63,    83,    -1,    -1,    -1,
      -1,    -1,    13,    14,    72,    73,    17,    -1,    19,    -1,
      -1,    63,    -1,    -1,    -1,    83,    -1,    -1,    29,    30,
      72,    73,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    83,    13,    14,    -1,    -1,    17,    -1,    -1,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      83,    -1,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,     3,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    13,    14,    -1,    -1,    17,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    29,
      30,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      63,    64,    65,    66,    67,    68,    69,    70,    29,    30,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    59,
      -1,    -1,    14,    63,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    73,    74,    75,    76,    29,    30,    -1,
      -1,    14,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    73,    74,    75,    76,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    29,
      30,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      63,    64,    65,    66,    67,    68,    69,    70,    16,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,    29,    30,    63,    64,    65,    66,    67,    68,    69,
      70,    16,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    70,    29,    30,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    70,    29,    30,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    29,    30,    -1,
      63,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    73,    74,    75,    76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    13,    29,    30,    63,    64,    65,    66,    67,
      68,    69,    70,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    86,    87,   107,   108,   109,   110,   111,   113,
     119,   120,   121,   122,   125,   106,   107,   110,    73,   109,
      40,     0,   108,    13,    17,    15,    73,    93,    94,   125,
     126,   125,    15,    73,    15,    73,   125,   125,   109,   107,
     110,    14,     3,     5,     6,    11,    12,    13,    23,    26,
      63,    72,    73,    83,   127,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   146,
     147,    14,    73,   102,   103,   104,   105,   125,    18,   127,
      16,    19,    35,    37,    52,    53,    54,    55,    56,    57,
      58,    60,    61,    63,    73,    88,    89,    90,    91,    92,
      93,    94,    95,    96,   128,   130,   131,   144,    94,   126,
      19,   109,   123,   124,   111,   112,    15,   110,   116,   117,
     118,   121,    15,    93,    94,    13,   144,   144,    73,   101,
     116,   128,    13,   143,    82,     8,     9,    24,    25,    23,
      31,    32,    33,    34,    38,    39,    27,    28,     5,     6,
       3,     4,    20,   142,    11,    12,    13,    17,    71,    84,
      14,    51,    51,    14,    13,    17,    99,   100,   107,   109,
      18,    13,    13,    73,    19,    19,    19,   128,    73,    96,
      13,    13,   127,    59,    59,    16,    96,    16,    92,    19,
      51,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,   129,    40,    19,    51,    16,    51,   112,   116,
      59,   109,   114,   115,   118,    16,   117,   116,   118,    94,
      14,    13,   100,   107,    14,   101,   128,   134,   133,   135,
     136,   137,   138,   138,   139,   139,   139,   139,   140,   140,
     141,   141,   142,   142,   142,    14,   130,   145,   128,    73,
      73,    73,    62,   103,    14,   100,   105,    18,   127,    13,
      17,    99,   128,   128,    19,    19,    37,    91,   128,    59,
      96,    96,    16,   130,   130,    15,    98,   130,   123,   111,
      16,   127,    59,    19,    51,    16,   142,    14,    59,    14,
      51,    18,    14,    14,    18,    14,   105,    18,   127,    14,
      14,    13,    91,    14,    96,    97,    98,   127,   114,   131,
     130,    14,    18,    96,    96,   128,    14,   128,    96,    16,
      51,    36,    14,    96,    14,    16,    98,    96,    19,    96
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    87,    87,    87,    88,    88,    88,
      88,    88,    89,    89,    89,    89,    90,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    94,    94,    95,
      95,    95,    96,    96,    96,    96,    96,    96,    97,    97,
      98,    98,    98,    99,    99,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   100,   101,   101,   102,   102,   103,
     103,   103,   104,   104,   105,   105,   106,   106,   107,   107,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   109,
     109,   110,   110,   111,   111,   112,   112,   113,   113,   113,
     114,   114,   114,   115,   115,   116,   116,   116,   116,   117,
     118,   118,   119,   119,   120,   120,   120,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   122,   122,
     122,   122,   122,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   126,   126,   127,   128,   128,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   137,   137,   137,   138,   138,   138,   138,
     138,   139,   139,   139,   140,   140,   140,   141,   141,   141,
     141,   142,   142,   143,   143,   143,   143,   143,   144,   144,
     144,   144,   144,   144,   145,   145,   146,   146,   146,   146,
     146,   146,   146,   146,   147,   147,   147,   147
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     4,     3,     3,     2,     3,     2,     2,
       2,     3,     5,     7,     6,     7,     5,     7,     5,     1,
       2,     1,     2,     1,     2,     2,     3,     3,     4,     3,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     4,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     1,     1,     2,     1,     2,     1,     3,     2,
       1,     2,     1,     3,     1,     3,     1,     2,     1,     2,
       2,     3,     1,     3,     4,     3,     3,     4,     4,     2,
       1,     1,     1,     1,     3,     1,     3,     4,     5,     2,
       1,     2,     3,     1,     3,     2,     1,     2,     1,     3,
       1,     2,     1,     1,     5,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     2,     1,
       2,     1,     2,     2,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     5,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     4,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     4,     1,     3,     1,     3,     2,     2,
       3,     4,     4,     3,     1,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 55 "src/parser.y"
                    { g_root = (yyvsp[0].expr); }
#line 1869 "src/parser.tab.cpp"
    break;

  case 96:
#line 216 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr);}
#line 1875 "src/parser.tab.cpp"
    break;

  case 205:
#line 388 "src/parser.y"
                                          { (yyval.expr) = (yyvsp[-1].expr); }
#line 1881 "src/parser.tab.cpp"
    break;


#line 1885 "src/parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 393 "src/parser.y"


const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}

