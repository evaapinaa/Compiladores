/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "miniC.y"

        #include <stdio.h>
        #include <string.h>
        #include "listaSimbolos.h"
        Lista tabSimb;
        Tipo tipo;
        void yyerror(const char * s);
        char *obtenerEtiqueta();
        char *concatenaCads(char *cad1, char *cad2);
        char *concatenaCadNum(char *cad, int num);
        void imprimirCodigo();
        void insertarTS(char *nombre, Tipo tipo);
        int perteneceTabSimb(char *nombre);
        void imprimirTabSimb(Lista tabSimb);
        char *asignarRegistroTemporal();
        void liberarReg(char *registro);
        int esConstante(char* nombre);
        int contadorEtiquetas = 1;
        int contadorCadenas = 1;
        int numErroresSintacticos = 0;
        int numErroresSemanticos = 0;
        extern int numErroresLexicos;
        extern int yylex();
        extern int yylineno;
        int tablaRegistrosTemporales[10] = {0};

#line 98 "miniC.tab.c"

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

#include "miniC.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DO = 3,                         /* DO  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_CONST = 5,                      /* CONST  */
  YYSYMBOL_LPAREN = 6,                     /* LPAREN  */
  YYSYMBOL_DPAREN = 7,                     /* DPAREN  */
  YYSYMBOL_LEFTKEY = 8,                    /* LEFTKEY  */
  YYSYMBOL_RIGHTKEY = 9,                   /* RIGHTKEY  */
  YYSYMBOL_COMMA = 10,                     /* COMMA  */
  YYSYMBOL_ASSIGNOP = 11,                  /* ASSIGNOP  */
  YYSYMBOL_SEMICOLON = 12,                 /* SEMICOLON  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_PRINT = 14,                     /* PRINT  */
  YYSYMBOL_READ = 15,                      /* READ  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_MINUSOP = 17,                   /* MINUSOP  */
  YYSYMBOL_MULTIPLICATION = 18,            /* MULTIPLICATION  */
  YYSYMBOL_DIVISION = 19,                  /* DIVISION  */
  YYSYMBOL_PLUSOP = 20,                    /* PLUSOP  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_INTLITERAL = 23,                /* INTLITERAL  */
  YYSYMBOL_STRING = 24,                    /* STRING  */
  YYSYMBOL_ID = 25,                        /* ID  */
  YYSYMBOL_YYACCEPT = 26,                  /* $accept  */
  YYSYMBOL_program = 27,                   /* program  */
  YYSYMBOL_28_1 = 28,                      /* $@1  */
  YYSYMBOL_declarations = 29,              /* declarations  */
  YYSYMBOL_30_2 = 30,                      /* $@2  */
  YYSYMBOL_31_3 = 31,                      /* $@3  */
  YYSYMBOL_identifier_list = 32,           /* identifier_list  */
  YYSYMBOL_identifier = 33,                /* identifier  */
  YYSYMBOL_statement_list = 34,            /* statement_list  */
  YYSYMBOL_statement = 35,                 /* statement  */
  YYSYMBOL_print_list = 36,                /* print_list  */
  YYSYMBOL_print_item = 37,                /* print_item  */
  YYSYMBOL_read_list = 38,                 /* read_list  */
  YYSYMBOL_expression = 39                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  36
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  85

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    53,    66,    66,    72,    72,    77,    80,
      81,    88,   100,   121,   125,   128,   150,   151,   187,   209,
     244,   268,   269,   272,   273,   277,   304,   334,   367,   403,
     416,   430,   444,   457,   468,   469,   484
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DO", "VAR", "CONST",
  "LPAREN", "DPAREN", "LEFTKEY", "RIGHTKEY", "COMMA", "ASSIGNOP",
  "SEMICOLON", "WHILE", "PRINT", "READ", "MINUS", "MINUSOP",
  "MULTIPLICATION", "DIVISION", "PLUSOP", "IF", "ELSE", "INTLITERAL",
  "STRING", "ID", "$accept", "program", "$@1", "declarations", "$@2",
  "$@3", "identifier_list", "identifier", "statement_list", "statement",
  "print_list", "print_item", "read_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -29,    11,    14,   -29,    44,    38,    52,   -29,    21,   -29,
     -29,    15,    41,    41,    48,   -29,   -29,    65,    66,    73,
      79,    75,   -29,    76,     5,   -29,    55,    80,    34,    29,
      -3,    67,    29,    29,    29,    41,   -29,   -29,    96,   -29,
      29,    29,   -29,   -29,    57,   -29,     9,   -29,    81,   -29,
      31,    63,   -10,    81,   -29,    29,    71,   -29,    48,    29,
      29,    29,    29,    91,    -3,    92,    82,    48,   -29,    77,
     -29,   -29,    39,   -29,   -29,    39,   -29,   -29,   -29,   -29,
      83,    94,    48,   -29,   -29
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     8,    14,     4,
       6,     0,     0,     0,     0,    14,     3,     0,     0,     0,
       0,     0,    13,    11,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     7,     0,    16,
       0,     0,    36,    35,     0,    26,     0,    23,    25,    27,
       0,     0,     0,    12,    10,     0,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
      34,    19,    30,    31,    32,    29,    21,    24,    22,    28,
      18,     0,     0,    20,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,   -29,   -29,   -29,   -29,    95,    74,    97,   -14,
     -29,    46,   -29,   -28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     8,    12,    13,    24,    25,    11,    22,
      46,    47,    50,    48
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,    44,    68,    40,    51,    52,    53,    59,    60,    61,
      62,     3,    56,    57,    41,    35,    63,    36,    14,    64,
      42,    45,    43,    15,    16,     9,    10,    69,    17,    18,
      19,    72,    73,    74,    75,    40,    20,    14,    65,     4,
      21,    66,    15,    39,    71,     6,    41,    17,    18,    19,
       5,    14,    42,    80,    43,    20,    15,    60,    61,    21,
       7,    17,    18,    19,    58,    35,    23,    37,    84,    20,
      67,    29,    30,    21,    59,    60,    61,    62,    70,    31,
      59,    60,    61,    62,    81,    32,    33,    34,    59,    60,
      61,    62,    49,    38,    59,    60,    61,    62,    59,    60,
      61,    62,    55,    76,    78,    82,    83,    79,    26,    54,
      77,     0,    28
};

static const yytype_int8 yycheck[] =
{
      14,    29,    12,     6,    32,    33,    34,    17,    18,    19,
      20,     0,    40,    41,    17,    10,     7,    12,     3,    10,
      23,    24,    25,     8,     9,     4,     5,    55,    13,    14,
      15,    59,    60,    61,    62,     6,    21,     3,     7,    25,
      25,    10,     8,     9,    58,     7,    17,    13,    14,    15,
       6,     3,    23,    67,    25,    21,     8,    18,    19,    25,
       8,    13,    14,    15,     7,    10,    25,    12,    82,    21,
       7,     6,     6,    25,    17,    18,    19,    20,     7,     6,
      17,    18,    19,    20,     7,     6,    11,    11,    17,    18,
      19,    20,    25,    13,    17,    18,    19,    20,    17,    18,
      19,    20,     6,    12,    12,    22,    12,    25,    13,    35,
      64,    -1,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    28,     0,    25,     6,     7,     8,    29,     4,
       5,    34,    30,    31,     3,     8,     9,    13,    14,    15,
      21,    25,    35,    25,    32,    33,    32,    35,    34,     6,
       6,     6,     6,    11,    11,    10,    12,    12,    13,     9,
       6,    17,    23,    25,    39,    24,    36,    37,    39,    25,
      38,    39,    39,    39,    33,     6,    39,    39,     7,    17,
      18,    19,    20,     7,    10,     7,    10,     7,    12,    39,
       7,    35,    39,    39,    39,    39,    12,    37,    12,    25,
      35,     7,    22,    12,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    26,    28,    27,    30,    29,    31,    29,    29,    32,
      32,    33,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    35,    36,    36,    37,    37,    38,    38,    39,
      39,    39,    39,    39,    39,    39,    39
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     0,     5,     0,     5,     0,     1,
       3,     1,     3,     2,     0,     4,     3,     7,     5,     5,
       7,     5,     5,     1,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     2,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* $@1: %empty  */
#line 53 "miniC.y"
          { tabSimb = creaLS();}
#line 1445 "miniC.tab.c"
    break;

  case 3: /* program: $@1 ID LPAREN DPAREN LEFTKEY declarations statement_list RIGHTKEY  */
#line 53 "miniC.y"
                                                                                               {
                                                                                                    if(numErroresLexicos == 0 && numErroresSintacticos == 0 && numErroresSemanticos == 0) {
                                                                                                        imprimirTabSimb(tabSimb);
                                                                                                        concatenaLC((yyvsp[-2].codigo), (yyvsp[-1].codigo));
                                                                                                        imprimirCodigo((yyvsp[-2].codigo));
                                                                                                    }
                                                                                                    
                                                                                                    liberaLC((yyvsp[-2].codigo)); 
                                                                                                    liberaLC((yyvsp[-1].codigo)); 
                                                                                                    liberaLS(tabSimb); 
                                                                                               }
#line 1461 "miniC.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 66 "miniC.y"
                                { tipo = VARIABLE; }
#line 1467 "miniC.tab.c"
    break;

  case 5: /* declarations: declarations VAR $@2 identifier_list SEMICOLON  */
#line 66 "miniC.y"
                                                                               { 
                                                                                    (yyval.codigo) = (yyvsp[-4].codigo);
                                                                                    concatenaLC((yyval.codigo), (yyvsp[-1].codigo));
                                                                                    liberaLC((yyvsp[-1].codigo));
                                                                                                                                                               
                                                                                }
#line 1478 "miniC.tab.c"
    break;

  case 6: /* $@3: %empty  */
#line 72 "miniC.y"
                                  { tipo = CONSTANTE; }
#line 1484 "miniC.tab.c"
    break;

  case 7: /* declarations: declarations CONST $@3 identifier_list SEMICOLON  */
#line 72 "miniC.y"
                                                                                  {
                                                                                    (yyval.codigo) = (yyvsp[-4].codigo);
                                                                                    concatenaLC((yyval.codigo), (yyvsp[-1].codigo));
                                                                                    liberaLC((yyvsp[-1].codigo));
                                                                                    }
#line 1494 "miniC.tab.c"
    break;

  case 8: /* declarations: %empty  */
#line 77 "miniC.y"
               {(yyval.codigo) = creaLC();}
#line 1500 "miniC.tab.c"
    break;

  case 9: /* identifier_list: identifier  */
#line 80 "miniC.y"
                             { (yyval.codigo) = (yyvsp[0].codigo); }
#line 1506 "miniC.tab.c"
    break;

  case 10: /* identifier_list: identifier_list COMMA identifier  */
#line 81 "miniC.y"
                                                   {
                                                        (yyval.codigo) = (yyvsp[-2].codigo);
                                                        concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                                        liberaLC((yyvsp[0].codigo));   
                                                    }
#line 1516 "miniC.tab.c"
    break;

  case 11: /* identifier: ID  */
#line 89 "miniC.y"
                        { 
                            if(!perteneceTabSimb((yyvsp[0].lexema))) {
                                insertarTS((yyvsp[0].lexema),tipo);
                            }
                            else {
                                printf("\nERROR en la linea %d: variable %s ya declarada anteriormente.", yylineno,(yyvsp[0].lexema));
                                numErroresSemanticos++;
                            }
                            
                            (yyval.codigo) = creaLC();
                     }
#line 1532 "miniC.tab.c"
    break;

  case 12: /* identifier: ID ASSIGNOP expression  */
#line 100 "miniC.y"
                                    { 
                                        if(!perteneceTabSimb((yyvsp[-2].lexema))) {
                                            insertarTS((yyvsp[-2].lexema),tipo);
                                        }
                                        else {
                                            printf("\nERROR en la linea %d: variable %s ya declarada anteriormente.", yylineno,(yyvsp[-2].lexema));
                                            numErroresSemanticos++;
                                        }
                                
                                       
                                        (yyval.codigo) = (yyvsp[0].codigo);
                                        Operacion oper;
                                        oper.op = "sw";
                                        oper.res = recuperaResLC((yyvsp[0].codigo));
                                        oper.arg1 = concatenaCads("_",(yyvsp[-2].lexema));
                                        oper.arg2 = NULL;
                                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                        liberarReg(oper.res);
                                    }
#line 1556 "miniC.tab.c"
    break;

  case 13: /* statement_list: statement_list statement  */
#line 121 "miniC.y"
                                          {  (yyval.codigo) = (yyvsp[-1].codigo);
				                             concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                             liberaLC((yyvsp[0].codigo));
                                             }
#line 1565 "miniC.tab.c"
    break;

  case 14: /* statement_list: %empty  */
#line 125 "miniC.y"
                 { (yyval.codigo) = creaLC(); }
#line 1571 "miniC.tab.c"
    break;

  case 15: /* statement: ID ASSIGNOP expression SEMICOLON  */
#line 128 "miniC.y"
                                                 { 
                                                  
                                                    if(!perteneceTabSimb((yyvsp[-3].lexema))) {
                                                        printf("\nERROR en la linea %d: variable %s no declarada.",yylineno,(yyvsp[-3].lexema)); ;     
                                                        numErroresSemanticos++;
                                                    }
                                                    else if (esConstante((yyvsp[-3].lexema))) {
                                                        printf("\nERROR en la linea %d: asignación a la constante %s.", yylineno, (yyvsp[-3].lexema));
                                                        numErroresSemanticos++;
                                                    }

                                                    (yyval.codigo) = (yyvsp[-1].codigo);
                                                    
                                                    Operacion oper;
                                                    oper.op = "sw";
                                                    oper.res = recuperaResLC((yyvsp[-1].codigo));
                                                    oper.arg1 = concatenaCads("_",(yyvsp[-3].lexema));
                                                    oper.arg2 = NULL;                                 
                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);             
                                                    liberarReg(oper.res);

                                               }
#line 1598 "miniC.tab.c"
    break;

  case 16: /* statement: LEFTKEY statement_list RIGHTKEY  */
#line 150 "miniC.y"
                                            { (yyval.codigo) = (yyvsp[-1].codigo); }
#line 1604 "miniC.tab.c"
    break;

  case 17: /* statement: IF LPAREN expression DPAREN statement ELSE statement  */
#line 151 "miniC.y"
                                                                 {
                                                                    (yyval.codigo) = (yyvsp[-4].codigo);
                                                                    Operacion oper1;
                                                                    Operacion oper2;
                                                                    Operacion oper3;
                                                                    Operacion oper4;
                                                            
                                                                    oper1.op = "beqz";
                                                                    oper1.res = recuperaResLC((yyvsp[-4].codigo));
                                                                    oper1.arg1 = obtenerEtiqueta();
                                                                    oper1.arg2 = NULL;
                                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
                                                                    concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
                                                                    liberaLC((yyvsp[-2].codigo));

                                                                    oper2.op = "b";
                                                                    oper2.res = obtenerEtiqueta();
                                                                    oper2.arg1 = NULL;
                                                                    oper2.arg2 = NULL;
                                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);
                                                                    
                                                                    oper3.op = "etiq";
                                                                    oper3.res = oper1.arg1;
                                                                    oper3.arg1 = NULL;
                                                                    oper3.arg2 = NULL;
                                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper3);
                                                                    concatenaLC((yyval.codigo), (yyvsp[0].codigo));                                                                    
                                                                    liberaLC((yyvsp[0].codigo));

                                                                    oper4.op = "etiq";
                                                                    oper4.res = oper2.res;
                                                                    oper4.arg1 = NULL;
                                                                    oper4.arg2 = NULL;
                                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper4);
                                                                    liberarReg(recuperaResLC((yyvsp[-4].codigo)));
                                                                }
#line 1645 "miniC.tab.c"
    break;

  case 18: /* statement: IF LPAREN expression DPAREN statement  */
#line 187 "miniC.y"
                                                     {

                                                                    (yyval.codigo) = (yyvsp[-2].codigo);
                                                                    Operacion oper1;
                                                                    Operacion oper2;
                                                            
                                                                    oper1.op = "beqz";
                                                                    oper1.res = recuperaResLC((yyvsp[-2].codigo));
                                                                    oper1.arg1 = obtenerEtiqueta();
                                                                    oper1.arg2 = NULL;
                                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
                                                                    concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                                                    liberaLC((yyvsp[0].codigo));
 
                                                                    oper2.op = "etiq";
                                                                    oper2.res = oper1.arg1;
                                                                    oper2.arg1 = NULL;
                                                                    oper2.arg2 = NULL;
                                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);
                                                                    liberarReg(recuperaResLC((yyval.codigo)));

                                                     }
#line 1672 "miniC.tab.c"
    break;

  case 19: /* statement: WHILE LPAREN expression DPAREN statement  */
#line 209 "miniC.y"
                                                                        { 
                                                                    (yyval.codigo) = (yyvsp[-2].codigo);
                                                                    Operacion oper1;
                                                                    Operacion oper2;
                                                                    Operacion oper3;
                                                                    Operacion oper4;
                                                                    
                                                                    oper1.op = "etiq";
                                                                    oper1.res = obtenerEtiqueta();
                                                                    oper1.arg1 = NULL;
                                                                    oper1.arg2 = NULL;
                                                                    insertaLC((yyval.codigo), inicioLC((yyval.codigo)), oper1); 

                                                                    oper2.op = "beqz";
                                                                    oper2.res = recuperaResLC((yyvsp[-2].codigo));
                                                                    oper2.arg1 = obtenerEtiqueta();
                                                                    oper2.arg2 = NULL;
                                                                    insertaLC((yyval.codigo),finalLC((yyval.codigo)), oper2);
                                                                    concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                                                    liberaLC((yyvsp[0].codigo));

                                                                    oper3.op = "b";
                                                                    oper3.res = oper1.res;
                                                                    oper3.arg1 = NULL;
                                                                    oper3.arg2 = NULL;
                                                                    insertaLC((yyval.codigo),finalLC((yyval.codigo)), oper3);

                                                                    oper4.op = "etiq";
                                                                    oper4.res = oper2.arg1;
                                                                    oper4.arg1 = NULL;
                                                                    oper4.arg2 = NULL;
                                                                    insertaLC((yyval.codigo),finalLC((yyval.codigo)), oper4);
                                                                    liberarReg(recuperaResLC((yyval.codigo)));
                                                                    
                                                                }
#line 1712 "miniC.tab.c"
    break;

  case 20: /* statement: DO statement WHILE LPAREN expression DPAREN SEMICOLON  */
#line 244 "miniC.y"
                                                                {

                                                                    (yyval.codigo) = creaLC();
                                                                    Operacion oper1;
                                                                    Operacion oper2;
                                                                    Operacion oper3;


                                                                    oper1.op = "etiq";
                                                                    oper1.res = obtenerEtiqueta();
                                                                    oper1.arg1 = NULL;
                                                                    oper1.arg2 = NULL;
                                                                    insertaLC((yyval.codigo), inicioLC((yyval.codigo)), oper1); 
                                                                    concatenaLC((yyval.codigo), (yyvsp[-5].codigo));
                                                                    concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
                                                                    oper2.op = "bnez";
                                                                    oper2.res = recuperaResLC((yyvsp[-2].codigo));
                                                                    oper2.arg1 = oper1.res;
                                                                    oper2.arg2 = NULL;
                                                                    insertaLC((yyval.codigo),finalLC((yyval.codigo)), oper2);
                                                                    liberaLC((yyvsp[-2].codigo));
                                                                    liberaLC((yyvsp[-5].codigo));

                                                                }
#line 1741 "miniC.tab.c"
    break;

  case 21: /* statement: PRINT LPAREN print_list DPAREN SEMICOLON  */
#line 268 "miniC.y"
                                                     { (yyval.codigo)=(yyvsp[-2].codigo);}
#line 1747 "miniC.tab.c"
    break;

  case 22: /* statement: READ LPAREN read_list DPAREN SEMICOLON  */
#line 269 "miniC.y"
                                                   { (yyval.codigo)=(yyvsp[-2].codigo);}
#line 1753 "miniC.tab.c"
    break;

  case 23: /* print_list: print_item  */
#line 272 "miniC.y"
                        { (yyval.codigo) = (yyvsp[0].codigo);}
#line 1759 "miniC.tab.c"
    break;

  case 24: /* print_list: print_list COMMA print_item  */
#line 273 "miniC.y"
                                         { (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo), (yyvsp[0].codigo)); }
#line 1765 "miniC.tab.c"
    break;

  case 25: /* print_item: expression  */
#line 277 "miniC.y"
                        {
                        (yyval.codigo) = (yyvsp[0].codigo);

                        Operacion oper1;
                        Operacion oper2;
                        Operacion oper3;

                        oper1.op = "move";
                        oper1.res = "$a0";
                        oper1.arg1 = recuperaResLC((yyvsp[0].codigo));
                        oper1.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);

                        oper2.op = "li";
                        oper2.res = "$v0";
                        oper2.arg1 = "1";
                        oper2.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);
                        
                        oper3.op = "syscall";
                        oper3.res = NULL;
                        oper3.arg1 = NULL;
                        oper3.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper3);
                        liberarReg(recuperaResLC((yyvsp[0].codigo)));

                    }
#line 1797 "miniC.tab.c"
    break;

  case 26: /* print_item: STRING  */
#line 304 "miniC.y"
                    {
                        insertarTS((yyvsp[0].lexema), CADENA); 
                        contadorCadenas++;
                        (yyval.codigo) = creaLC();

                        Operacion oper1;
                        Operacion oper2;
                        Operacion oper3;
                        
                        oper1.op = "la";
                        oper1.res = "$a0";
                        oper1.arg1 = concatenaCadNum("$str", contadorCadenas-1);
                        oper1.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);

                        oper2.op = "li";
                        oper2.res = "$v0";
                        oper2.arg1 = "4";
                        oper2.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);

                        oper3.op = "syscall";
                        oper3.res = NULL;
                        oper3.arg1 = NULL;
                        oper3.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper3);

                    }
#line 1830 "miniC.tab.c"
    break;

  case 27: /* read_list: ID  */
#line 334 "miniC.y"
                                { 
                                                if(!perteneceTabSimb((yyvsp[0].lexema))) {
                                                    printf("\nERROR en la linea %d: variable %s no declarada.",yylineno,(yyvsp[0].lexema));
                                                    numErroresSemanticos++;
                                                }
                                                else if (esConstante((yyvsp[0].lexema))) {
                                                    printf("\nERROR en la linea %d: asignación a la constante %s.", yylineno, (yyvsp[0].lexema));
                                                    numErroresSemanticos++;
                                                }
                                                
                                                (yyval.codigo) = creaLC();
                                                Operacion oper1;
                                                Operacion oper2;
                                                Operacion oper3;

                                                oper1.op = "li";
                                                oper1.res = "$v0";
                                                oper1.arg1 = "5";
                                                oper1.arg2 = NULL;
                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
            
                                                oper2.op = "syscall";
                                                oper2.res = NULL;
                                                oper2.arg1 = NULL;
                                                oper2.arg2 = NULL;
                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);
                                                
                                                oper3.op = "sw";
                                                oper3.res = "$v0";
                                                oper3.arg1 = concatenaCads("_",(yyvsp[0].lexema));
                                                oper3.arg2 = NULL;
                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper3);
                                }
#line 1868 "miniC.tab.c"
    break;

  case 28: /* read_list: read_list COMMA ID  */
#line 367 "miniC.y"
                                { 
                                                if (!perteneceTabSimb((yyvsp[0].lexema))) {
                                                    printf("\nERROR, %s ya declarado anteriormente.", (yyvsp[0].lexema));     
                                                    numErroresSemanticos++;
                                                }
                                                else if (esConstante((yyvsp[0].lexema))) {
                                                    printf("\nERROR en la linea %d: asignación a la constante %s.", yylineno, (yyvsp[-2].codigo));
                                                    numErroresSemanticos++;
                                                }

                                                (yyval.codigo) = (yyvsp[-2].codigo);

                                                Operacion oper1;
                                                Operacion oper2;
                                                Operacion oper3;
                                                
                                                oper1.op = "li";
                                                oper1.res = "$v0";
                                                oper1.arg1 = "5";
                                                oper1.arg2 = NULL;
                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
                                                
                                                oper2.op = "syscall";
                                                oper2.res = NULL;
                                                oper2.arg1 = NULL;
                                                oper2.arg2 = NULL;
                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);
                                                
                                                oper3.op = "sw";
                                                oper3.res = "$v0";
                                                oper3.arg1 = concatenaCads("_", (yyvsp[0].lexema));
                                                oper3.arg2 = NULL;
                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper3);
                                }
#line 1907 "miniC.tab.c"
    break;

  case 29: /* expression: expression PLUSOP expression  */
#line 403 "miniC.y"
                                                        {
                                                            (yyval.codigo) = (yyvsp[-2].codigo);
                                                            concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                                            Operacion oper;
                                                            oper.op = "add";
                                                            oper.res = asignarRegistroTemporal(); 
                                                            oper.arg1 = recuperaResLC((yyvsp[-2].codigo));    
                                                            oper.arg2 = recuperaResLC((yyvsp[0].codigo));    
                                                            insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                            guardaResLC((yyval.codigo),oper.res);
                                                            liberarReg(oper.arg2);
                                                            liberaLC((yyvsp[0].codigo)); 
                                                        }
#line 1925 "miniC.tab.c"
    break;

  case 30: /* expression: expression MINUSOP expression  */
#line 416 "miniC.y"
                                                        {   
                                                            (yyval.codigo) = (yyvsp[-2].codigo);
                                                            concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                                            Operacion oper;
                                                            oper.op = "sub";
                                                            oper.res = asignarRegistroTemporal(); 
                                                            oper.arg1 = recuperaResLC((yyvsp[-2].codigo));   
                                                            oper.arg2 = recuperaResLC((yyvsp[0].codigo));  
                                                            insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                            guardaResLC((yyval.codigo),oper.res);
                                                            liberarReg(oper.arg2);
                                                            liberaLC((yyvsp[0].codigo));                            

                                                        }
#line 1944 "miniC.tab.c"
    break;

  case 31: /* expression: expression MULTIPLICATION expression  */
#line 430 "miniC.y"
                                                         {
                                                            (yyval.codigo) = (yyvsp[-2].codigo);
                                                            concatenaLC((yyval.codigo), (yyvsp[0].codigo));    
                                                            Operacion oper;
                                                            oper.op = "mul";
                                                            oper.res = asignarRegistroTemporal(); 
                                                            oper.arg1 = recuperaResLC((yyvsp[-2].codigo));    
                                                            oper.arg2 = recuperaResLC((yyvsp[0].codigo));  
                                                            insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                            guardaResLC((yyval.codigo),oper.res);
                                                            liberarReg(oper.arg2);
                                                            liberaLC((yyvsp[0].codigo));              

                                                        }
#line 1963 "miniC.tab.c"
    break;

  case 32: /* expression: expression DIVISION expression  */
#line 444 "miniC.y"
                                                        {
                                                            (yyval.codigo) = (yyvsp[-2].codigo);
                                                            concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                                            Operacion oper;
                                                            oper.op = "div";
                                                            oper.res = asignarRegistroTemporal();
                                                            oper.arg1 = recuperaResLC((yyvsp[-2].codigo));     
                                                            oper.arg2 = recuperaResLC((yyvsp[0].codigo));    
                                                            insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                            guardaResLC((yyval.codigo),oper.res);
                                                            liberarReg(oper.arg2);
                                                            liberaLC((yyvsp[0].codigo));
                                                        }
#line 1981 "miniC.tab.c"
    break;

  case 33: /* expression: MINUSOP expression  */
#line 457 "miniC.y"
                                                        {  
                                                            (yyval.codigo) = (yyvsp[0].codigo); 
                                                            Operacion oper;
                                                            oper.op = "neg";
                                                            oper.res = asignarRegistroTemporal();
                                                            oper.arg1 = recuperaResLC((yyvsp[0].codigo));    
                                                            oper.arg2 = NULL;
                                                            insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                            guardaResLC((yyval.codigo), oper.res);
                                                            
                                                        }
#line 1997 "miniC.tab.c"
    break;

  case 34: /* expression: LPAREN expression DPAREN  */
#line 468 "miniC.y"
                                                        {   (yyval.codigo)=(yyvsp[-1].codigo); }
#line 2003 "miniC.tab.c"
    break;

  case 35: /* expression: ID  */
#line 469 "miniC.y"
                                                        {
                                                        
                                                            if (!perteneceTabSimb((yyvsp[0].lexema))) {
                                                                printf("\nERROR en la linea %d: variable %s no declarada.", yylineno,(yyvsp[0].lexema)); 
                                                                numErroresSemanticos++; 
                                                            }
                                                            (yyval.codigo) = creaLC();
                                                            Operacion oper;
                                                            oper.op = "lw";
                                                            oper.res = asignarRegistroTemporal();
                                                            oper.arg1 = concatenaCads("_", (yyvsp[0].lexema));
                                                            oper.arg2 = NULL;
                                                            insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                            guardaResLC((yyval.codigo), oper.res);
                                                        }
#line 2023 "miniC.tab.c"
    break;

  case 36: /* expression: INTLITERAL  */
#line 484 "miniC.y"
                                                        {
                                                            (yyval.codigo) = creaLC();
                                                            Operacion oper;
                                                            oper.op = "li";
                                                            oper.res = asignarRegistroTemporal();
                                                            oper.arg1 = (yyvsp[0].lexema);
                                                            oper.arg2 = NULL;
                                                            insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);    
                                                            guardaResLC((yyval.codigo), oper.res);
                                                        }
#line 2038 "miniC.tab.c"
    break;


#line 2042 "miniC.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 496 "miniC.y"




void imprimirTabSimb(Lista tabSimb) {
	printf("#####################\n");
	printf("# Seccion de datos\n");
	printf("   .data\n");
	PosicionLista p= inicioLS(tabSimb);
	while (p != finalLS(tabSimb)) {
		Simbolo aux = recuperaLS(tabSimb,p);
		if (aux.tipo == VARIABLE || aux.tipo == CONSTANTE){
			printf("_%s:\n   .word 0\n", aux.nombre);
		}
		else if (aux.tipo == CADENA){
			printf("$str%d:\n   .asciiz %s\n",aux.valor, aux.nombre);
		}
		p = siguienteLS(tabSimb,p);
	}
	printf("\n");
}


void insertarTS(char *nombre, Tipo tipo) {
	if (tipo == CADENA){
		Simbolo aux;
		aux.nombre = nombre;
		aux.tipo = tipo;
		aux.valor = contadorCadenas;
		insertaLS(tabSimb,finalLS(tabSimb), aux);
	} else {
		Simbolo aux;
		aux.nombre = nombre;
		aux.tipo = tipo;
		insertaLS(tabSimb,finalLS(tabSimb), aux);
	}
}

int perteneceTabSimb(char *nombre) {
    if (buscaLS(tabSimb, nombre) != finalLS(tabSimb))
	    return 1;
    else
        return 0;
}
int esConstante(char* nombre) {
    PosicionLista p = buscaLS(tabSimb, nombre);
  	Simbolo aux = recuperaLS(tabSimb, p);
  	if (aux.tipo == CONSTANTE) return 1;
  	return 0;
}


char *obtenerEtiqueta() {
    char aux[32];
    sprintf(aux,"$l%d",contadorEtiquetas++);
    return strdup(aux);
}

char *concatenaCads(char *cad1, char *cad2) {
    char *aux = malloc(strlen(cad1) + strlen(cad2) + 1);
    strcpy(aux, cad1);
    strcat(aux, cad2);
    return aux;
}

char *concatenaCadNum(char *cad, int num) {
    char aux[32];
    sprintf(aux,"%s%d",cad,num);
    return strdup(aux);
}

void imprimirCodigo(ListaC codigo){
	printf("#####################\n");
	printf("# Seccion de codigo\n");
	printf("   .text\n");
	printf("   .globl main\n");
	printf("main:\n");
	PosicionListaC p = inicioLC(codigo);
	while (p != finalLC(codigo)){
		Operacion oper = recuperaLC(codigo, p);
		if (oper.op == "etiq"){
			printf("%s:\n", oper.res);
		}
		else if (oper.op == "li" || oper.op == "la" || oper.op == "lw" || oper.op == "sw" || oper.op == "neg" || oper.op == "move" || oper.op == "beqz" || oper.op == "bnez" || oper.op == "b"){
			printf("   %s ", oper.op);
			if(oper.res) printf ("%s, ", oper.res);
			if(oper.arg1) printf ("%s", oper.arg1);
			if(oper.arg2) printf ("%s", oper.arg2);
			printf("\n");
	
			}
		else if (oper.op == "add" || oper.op == "sub" || oper.op == "div" || oper.op == "mul"){
			printf("   %s ", oper.op);
			if(oper.res) printf ("%s, ", oper.res);
			if(oper.arg1) printf ("%s, ", oper.arg1);
			if(oper.arg2) printf ("%s", oper.arg2);
			printf("\n");
		}
		else {
			printf("   %s ", oper.op);
			if(oper.res) printf ("%s", oper.res);
			if(oper.arg1) printf ("%s", oper.arg1);
			if(oper.arg2) printf ("%s", oper.arg2);
			printf("\n");
		}
		p = siguienteLC(codigo, p);	
	}
	printf("\n");
	printf("#####################\n");
	printf("# Fin\n");
    printf("   li $v0, 10\n");
    printf("   syscall\n");
}

char * asignarRegistroTemporal() {
  char aux[32];
  for(int i = 0; i < 10; i++) {
    if(tablaRegistrosTemporales[i] == 0) {
        tablaRegistrosTemporales[i] = 1;
        sprintf(aux,"$t%d",i);
        return strdup(aux);
    }
  }
}

void liberarReg(char *registro) {
    int i = registro[2] - '0';
    tablaRegistrosTemporales[i] = 0;
}

void yyerror(const char * s) {
    printf("\nERROR en la línea %d: %s\n",yylineno,s);
    numErroresSintacticos++;
}


