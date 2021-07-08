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




/* First part of user prologue.  */
#line 1 "calculator.y"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "expr.h"

#ifdef LEX_SELF
#include "myflex.h"
#else
#include "calculator_lex.h"
#endif
#include "calculator_yacc.h"


void yyerror(char * msg);
void PreOrder(struct node *root,int tab);
extern void Outputlist();
extern void OutputQ();
extern void UpdateQlist(char *Op,int index1,int index2,int result,int x);
extern int newtemp();
extern int insertNXQ(int no,char *Op,int index1,int index2,int result);
extern void conti_update_Quterlist(int start,int end);
extern void setcontinueflag(int line);
extern void setbreakflag(int line);

extern int line_no;
extern struct node root;
extern int Varcount;
extern char str1[20];
extern char str2[20];
extern char str0[20];
extern int NXQ;
extern int fflag;
extern int tempnum;

#line 108 "calculator_yacc.c"

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
#ifndef YY_YY_CALCULATOR_YACC_H_INCLUDED
# define YY_YY_CALCULATOR_YACC_H_INCLUDED
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
    IDENT = 402,
    NUM = 403,
    INT = 404,
    VOID = 405,
    BREAK = 406,
    CONTINUE = 407,
    RETURN = 408,
    WHILE = 409,
    IF = 410,
    ELSE = 411,
    OR = 422,
    AND = 423,
    DDU = 424,
    XDU = 427,
    DU = 428,
    BDU = 429,
    INC = 436,
    DEC = 437
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "calculator.y"

    struct node *ast_node; 
    int number;
    char str[20];
    struct { int Iv; struct node *ast_node;} _Type; /*int 0 void 1*/
    struct { int place; int isarray; struct node *ast_node;} _Type_defdata;
     /* place means ident's no. in varlist 
        isarray means is array 1 or not 0    2 means '*' ident */
    struct { int startplace; int endplace; struct node *ast_node;} _Type_localdef;
    struct { int place[20];int isarray[20]; int length; struct node *ast_node;} _Type_deflist;
    struct { int place[20]; int varplace; int isarray[20]; int length; struct node *ast_node;} _Type_idtail;
    /**/
    struct { int Iv; char op[5]; struct node *ast_node;} _Type_rop;
    struct { int length; int place[20]; char op[20][5]; struct node *ast_node;} _Type_itemtail;
    struct { int place; int startNXQ; int endNXQ; struct node *ast_node;} _Type_midexpr;
    /* */
    

#line 200 "calculator_yacc.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CALCULATOR_YACC_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

#define YYUNDEFTOK  2
#define YYMAXUTOK   438


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
       2,     2,     2,    36,     2,     2,     2,     2,    37,     2,
      29,    30,     5,     3,    25,     4,     2,     6,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    26,
      35,    33,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
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
       2,     2,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    17,    18,    19,     2,     2,    20,    21,    22,
       2,     2,     2,     2,     2,     2,    23,    24,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   144,   144,   145,   152,   170,   177,   184,   202,   223,
     242,   250,   256,   268,   283,   293,   312,   325,   330,   339,
     344,   352,   366,   377,   390,   398,   408,   414,   427,   435,
     441,   454,   462,   480,   490,   501,   524,   535,   546,   557,
     568,   576,   587,   594,   605,   628,   636,   647,   663,   670,
     681,   692,   703,   711,   723,   734,   745,   762,   769,   787,
     806,   813,   831,   850,   857,   875,   894,   901,   920,   928,
     936,   944,   952,   960,   968,   987,   994,  1013,  1021,  1029,
    1049,  1057,  1077,  1085,  1093,  1107,  1118,  1127,  1135,  1143,
    1151,  1160,  1169,  1180,  1195,  1204,  1213,  1219,  1225,  1234,
    1243,  1254,  1259,  1266,  1273,  1284,  1289,  1298,  1303,  1311
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'+'", "'-'", "'*'", "'/'", "IDENT",
  "NUM", "INT", "VOID", "BREAK", "CONTINUE", "RETURN", "WHILE", "IF",
  "ELSE", "OR", "AND", "DDU", "XDU", "DU", "BDU", "INC", "DEC", "','",
  "';'", "'['", "']'", "'('", "')'", "'{'", "'}'", "'='", "'>'", "'<'",
  "'!'", "'&'", "$accept", "Program", "Segment", "Type", "Def", "Deflist",
  "Varrdef", "Defdata", "Idtail", "Para", "Sononearg", "Onepara",
  "Paradata", "Paradatatail", "Sonparadatatail", "Functail", "Block",
  "Subprogram", "Onestatement", "Localdef", "Statement", "Ifstat",
  "Elsestat", "Whilestat", "Returnstat", "Breakstat", "Continuestat",
  "Blockstat", "Emptystat", "Assignstat", "Altexpr", "Expr", "Assexpr",
  "Asstail", "Orexpr", "Ortail", "Andexpr", "Andtail", "Cmpexpr",
  "Cmptail", "Cmps", "Aloexpr", "Alotail", "Addsub", "Item", "Itemtail",
  "Muldiv", "Factor", "Lop", "Val", "Rop", "Incr", "Decr", "Elem",
  "Idexpr", "Literal", "Realarg", "Sonarg", "Arg", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   438,    43,    45,    42,    47,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   422,   423,   424,
     427,   428,   429,   436,   437,    44,    59,    91,    93,    40,
      41,   123,   125,    61,    62,    60,    33,    38
};
# endif

#define YYPACT_NINF (-87)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -87,     6,   -87,   -87,   -87,   -87,    27,    11,    -8,   -87,
      33,    61,   -17,   -87,    69,   -87,   -87,    72,     7,     8,
      32,   -87,    38,   -87,    33,    41,    28,   -87,   -19,    61,
     -87,    37,   -87,    66,   -87,   -87,     3,   -87,   -87,   -87,
     -87,   -87,   -87,     8,   -87,    73,    76,    15,   -87,    76,
      92,   -87,   -87,   -87,    65,   -87,    78,    79,    83,    81,
      82,   -87,   -87,   -87,    83,   -87,   -87,   -87,    69,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,    87,   -87,   -87,    84,    85,    90,    47,    80,    91,
      83,   -87,   -87,   -87,    75,   -87,   -87,    83,    83,   -87,
     -87,   -87,    88,    83,    83,    86,    33,   -87,    83,   -87,
      83,   -87,    83,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,    83,   -87,   -87,   -87,    83,   -87,   -87,   -87,    83,
     -87,   -87,   -87,   -87,    93,   -87,    94,    97,   -87,    95,
      98,   -87,   -87,    84,    85,    90,    47,    80,    91,   -87,
     -87,    83,   -87,    49,    96,   -87,   -87,   -87,   -87,   -87,
     -87,    97,   -87,    99,   -87,    96,   -87,   -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     5,     6,     3,     0,     0,    11,     4,
       0,    17,     0,     8,     0,    10,     7,     0,     0,    19,
       0,    15,     0,    11,     0,     0,    26,    21,     0,     0,
      18,     0,    14,    13,     9,    22,     0,    23,    25,    29,
      31,    16,    28,    19,    12,     0,    26,     0,    20,    26,
       0,    24,    87,    89,   101,   104,     0,     0,     0,     0,
       0,    96,    97,    52,     0,    30,    86,    88,     0,    51,
      32,    33,    34,    43,    36,    42,    37,    38,    39,    40,
      41,     0,    54,    55,    57,    60,    63,    66,    75,    80,
       0,    85,    90,    91,    92,   100,    27,     0,   105,    98,
      49,    50,     0,     0,     0,     0,     0,    53,     0,    56,
       0,    59,     0,    62,    68,    71,    72,    73,    69,    70,
      65,     0,    77,    78,    74,     0,    82,    83,    79,     0,
      84,    93,    94,    95,     0,   109,     0,   107,    48,     0,
       0,    99,    35,    57,    60,    63,    66,    75,    80,   102,
     103,     0,   106,     0,     0,    58,    61,    64,    67,    76,
      81,   107,    47,    45,   108,     0,    44,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -87,   -87,   -87,     2,   -87,   -11,   100,    50,   -87,   -87,
      89,   101,   -87,   -87,   -32,   -87,   -28,   -87,   -87,   -87,
     -44,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -53,   -62,    21,   -12,   -87,   -10,    23,    -9,    26,    -7,
     -87,    14,    -6,   -87,    17,    -5,   -87,   -86,   -87,   -87,
     -87,    46,    51,   -87,   -87,   -87,   -87,   -15,    -4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     5,    17,     9,    16,    12,    24,    13,    18,
      30,    19,    27,    37,    38,    41,    69,    47,    70,    71,
      72,    73,   166,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,   109,    84,   111,    85,   113,    86,   120,
     121,    87,   124,   125,    88,   128,   129,    89,    90,    91,
     131,    92,    93,    94,    99,    95,   136,   152,   137
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,    21,   105,     6,   130,   102,     2,    39,    14,    15,
      20,    45,    40,    34,    51,     3,     4,    96,    10,    52,
      53,    11,    54,    55,     3,     4,    56,    57,    58,    59,
      60,    46,     7,    29,     8,   134,   135,    28,    61,    62,
      31,    63,   140,   148,    64,    32,    40,    65,    35,    68,
     139,    66,    67,    52,    53,    36,    54,    55,    14,    15,
      56,    57,    58,    59,    60,    44,   114,   115,   116,   117,
       3,     4,    61,    62,    22,    63,    23,    25,    64,    26,
      40,   118,   119,   122,   123,    66,    67,    52,    53,   135,
      54,    55,    97,    20,    98,   142,   126,   127,    61,    62,
      45,    49,   110,    50,   100,   101,    61,    62,   112,   162,
     103,   104,    64,   107,   138,   165,   141,   108,   106,    66,
      67,   149,   151,    33,   150,   153,   163,    40,   154,   143,
      43,   155,    48,   144,   156,   146,   157,   167,   145,   158,
     132,   159,   147,   160,     0,   133,   164,   161
};

static const yytype_int16 yycheck[] =
{
      28,    12,    64,     1,    90,    58,     0,    26,    25,    26,
      27,     8,    31,    24,    46,     9,    10,    49,     7,     4,
       5,    29,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    28,     5,    25,     7,    97,    98,    30,    23,    24,
       8,    26,   104,   129,    29,     7,    31,    32,     7,    47,
     103,    36,    37,     4,     5,    27,     7,     8,    25,    26,
      11,    12,    13,    14,    15,    28,    19,    20,    21,    22,
       9,    10,    23,    24,     5,    26,     7,     5,    29,     7,
      31,    34,    35,     3,     4,    36,    37,     4,     5,   151,
       7,     8,    27,    27,    29,   106,     5,     6,    23,    24,
       8,    28,    17,    27,    26,    26,    23,    24,    18,   153,
      29,    29,    29,    26,    26,    16,    30,    33,    68,    36,
      37,    28,    25,    23,    30,    30,   154,    31,    30,   108,
      29,   143,    43,   110,   144,   121,   145,   165,   112,   146,
      94,   147,   125,   148,    -1,    94,   161,   151
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,     0,     9,    10,    40,    41,     5,     7,    42,
       7,    29,    44,    46,    25,    26,    43,    41,    47,    49,
      27,    43,     5,     7,    45,     5,     7,    50,    30,    25,
      48,     8,     7,    44,    43,     7,    27,    51,    52,    26,
      31,    53,    54,    49,    28,     8,    28,    55,    48,    28,
      27,    52,     4,     5,     7,     8,    11,    12,    13,    14,
      15,    23,    24,    26,    29,    32,    36,    37,    41,    54,
      56,    57,    58,    59,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    72,    74,    76,    79,    82,    85,
      86,    87,    89,    90,    91,    93,    52,    27,    29,    92,
      26,    26,    68,    29,    29,    69,    45,    26,    33,    71,
      17,    73,    18,    75,    19,    20,    21,    22,    34,    35,
      77,    78,     3,     4,    80,    81,     5,     6,    83,    84,
      85,    88,    89,    90,    69,    69,    94,    96,    26,    68,
      69,    30,    43,    70,    74,    76,    79,    82,    85,    28,
      30,    25,    95,    30,    30,    71,    73,    75,    77,    80,
      83,    96,    58,    54,    95,    16,    60,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    39,    40,    41,    41,    42,    42,    43,
      43,    44,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    49,    50,    50,    51,    51,    52,    52,    53,    53,
      54,    55,    55,    56,    56,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    60,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    71,    72,
      73,    73,    74,    75,    75,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    79,    80,    80,    81,    81,    82,
      83,    83,    84,    84,    85,    85,    86,    86,    86,    86,
      86,    86,    87,    87,    88,    88,    89,    90,    91,    91,
      91,    92,    92,    92,    93,    94,    94,    95,    95,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     3,     2,     3,
       1,     0,     4,     2,     2,     2,     4,     0,     2,     0,
       3,     2,     2,     2,     3,     1,     0,     4,     1,     1,
       3,     0,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     6,     0,     2,     5,     3,     2,
       2,     1,     1,     2,     1,     1,     2,     0,     3,     2,
       0,     3,     2,     0,     3,     2,     0,     3,     1,     1,
       1,     1,     1,     1,     2,     0,     3,     1,     1,     2,
       0,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     2,     3,
       1,     0,     3,     3,     1,     0,     2,     0,     3,     1
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
  case 3:
#line 146 "calculator.y"
            {
                (yyval._Type).ast_node=&root;
                (yyval._Type).ast_node->type=e_program;
                add_son_node(&root,(yyvsp[0]._Type).ast_node);
                set_node_val_str(&root,"Program");
            }
#line 1516 "calculator_yacc.c"
    break;

  case 4:
#line 153 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_segment;
                set_node_val_str((yyval._Type).ast_node, "Segment");
                add_son_node((yyval._Type).ast_node, (yyvsp[-1]._Type).ast_node);
                add_son_node((yyval._Type).ast_node, (yyvsp[0]._Type_deflist).ast_node);
                
                for (int i=1;i<=(yyvsp[0]._Type_deflist).length;i++)
                {
                    if ((yyvsp[0]._Type_deflist).isarray[i]==0) 
                        set_valist_type((yyvsp[0]._Type_deflist).place[i],(yyvsp[0]._Type_deflist).place[i],(yyvsp[-1]._Type).Iv); 
                    else if ((yyvsp[0]._Type_deflist).isarray[i]==1) 
                            set_valist_type((yyvsp[0]._Type_deflist).place[i],(yyvsp[0]._Type_deflist).place[i],2);
                        else if ((yyvsp[0]._Type_deflist).isarray[i]==2) 
                                set_valist_type((yyvsp[0]._Type_deflist).place[i],(yyvsp[0]._Type_deflist).place[i],3);
                }
            }
#line 1538 "calculator_yacc.c"
    break;

  case 5:
#line 171 "calculator.y"
            {
                (yyval._Type).Iv = 0;
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_type_int;
                set_node_val_str((yyval._Type).ast_node, "Type_INT");
            }
#line 1549 "calculator_yacc.c"
    break;

  case 6:
#line 178 "calculator.y"
            {
                (yyval._Type).Iv = 1;
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_type_void;
                set_node_val_str((yyval._Type).ast_node, "Type_VOID");
            }
#line 1560 "calculator_yacc.c"
    break;

  case 7:
#line 185 "calculator.y"
            {
                new_node(&((yyval._Type_deflist).ast_node));
                (yyval._Type_deflist).ast_node->type = e_def_deflist;
                set_node_val_str((yyval._Type_deflist).ast_node, "Def");
                add_son_node((yyval._Type_deflist).ast_node,(yyvsp[0]._Type_deflist).ast_node);

                (yyval._Type_deflist).length=(yyvsp[0]._Type_deflist).length+1;
                for (int i=1;i<=(yyvsp[0]._Type_deflist).length;i++)
                {
                    (yyval._Type_deflist).place[i]=(yyvsp[0]._Type_deflist).place[i];
                    (yyval._Type_deflist).isarray[i]=(yyvsp[0]._Type_deflist).isarray[i];
                }
                (yyval._Type_deflist).place[(yyval._Type_deflist).length]=entry(str0);
                (yyval._Type_deflist).isarray[(yyval._Type_deflist).length]=2;
                set_valist_cat((yyval._Type_deflist).place[(yyval._Type_deflist).length],(yyval._Type_deflist).place[(yyval._Type_deflist).length],6);
                fflag=0;
            }
#line 1582 "calculator_yacc.c"
    break;

  case 8:
#line 203 "calculator.y"
            {
                new_node(&((yyval._Type_deflist).ast_node));
                (yyval._Type_deflist).ast_node->type = e_def_idtail;
                set_node_val_str((yyval._Type_deflist).ast_node, "Def");
                add_son_node((yyval._Type_deflist).ast_node,(yyvsp[0]._Type_idtail).ast_node);

                (yyval._Type_deflist).length=(yyvsp[0]._Type_idtail).length+1;
                for (int i=1;i<=(yyvsp[0]._Type_idtail).length;i++)
                {
                    (yyval._Type_deflist).place[i]=(yyvsp[0]._Type_idtail).place[i];
                    (yyval._Type_deflist).isarray[i]=(yyvsp[0]._Type_idtail).isarray[i];
                }
                
                if (strlen(str0)==0) strcpy(str0,str1);
                (yyval._Type_deflist).place[(yyval._Type_deflist).length]=entry(str0);
                    if ((yyvsp[0]._Type_idtail).varplace==0) (yyval._Type_deflist).isarray[(yyval._Type_deflist).length]=0;
                    else            (yyval._Type_deflist).isarray[(yyval._Type_deflist).length]=1;
                set_valist_cat((yyval._Type_deflist).place[(yyval._Type_deflist).length],(yyval._Type_deflist).place[(yyval._Type_deflist).length],5);
                fflag=0;
            }
#line 1607 "calculator_yacc.c"
    break;

  case 9:
#line 224 "calculator.y"
                {
                    new_node(&((yyval._Type_deflist).ast_node));
                    (yyval._Type_deflist).ast_node->type = e_deflist;
                    set_node_val_str((yyval._Type_deflist).ast_node, "Deflist");
                    add_son_node((yyval._Type_deflist).ast_node,(yyvsp[-1]._Type_defdata).ast_node);
                    add_son_node((yyval._Type_deflist).ast_node,(yyvsp[0]._Type_deflist).ast_node);
                    
                    (yyval._Type_deflist).length=(yyvsp[0]._Type_deflist).length+1;
                    for (int i=1;i<=(yyvsp[0]._Type_deflist).length;i++)
                    {
                        (yyval._Type_deflist).place[i]=(yyvsp[0]._Type_deflist).place[i];
                        (yyval._Type_deflist).isarray[i]=(yyvsp[0]._Type_deflist).isarray[i];
                    }
                    (yyval._Type_deflist).place[(yyval._Type_deflist).length]=(yyvsp[-1]._Type_defdata).place;
                    (yyval._Type_deflist).isarray[(yyval._Type_deflist).length]=(yyvsp[-1]._Type_defdata).isarray;
                    /*put element's place to an array*/
                    /*unfinished*/
                }
#line 1630 "calculator_yacc.c"
    break;

  case 10:
#line 243 "calculator.y"
                {
                    new_node(&((yyval._Type_deflist).ast_node));
                    (yyval._Type_deflist).ast_node->type = e_deflist;
                    set_node_val_str((yyval._Type_deflist).ast_node, "Deflist");
                    (yyval._Type_deflist).length=0;
                }
#line 1641 "calculator_yacc.c"
    break;

  case 11:
#line 250 "calculator.y"
            {
                new_node(&((yyval._Type_defdata).ast_node));
                (yyval._Type_defdata).ast_node->type = e_varrdef_e;
                set_node_val_str((yyval._Type_defdata).ast_node, "Varrdef");
                (yyval._Type_defdata).place=0;
            }
#line 1652 "calculator_yacc.c"
    break;

  case 12:
#line 257 "calculator.y"
            {
                new_node(&((yyval._Type_defdata).ast_node));
                (yyval._Type_defdata).ast_node->type = e_varrdef;
                set_node_val_str((yyval._Type_defdata).ast_node, "Varrdef");
                add_son_node((yyval._Type_defdata).ast_node,(yyvsp[-3]._Type_defdata).ast_node);

                (yyval._Type_defdata).place=entry(str2);
                /*printf("Vget %d %s\n",$$.place,str2);*/
                set_valist_type((yyval._Type_defdata).place,(yyval._Type_defdata).place,0);
                set_valist_cat((yyval._Type_defdata).place,(yyval._Type_defdata).place,2);
            }
#line 1668 "calculator_yacc.c"
    break;

  case 13:
#line 269 "calculator.y"
            {
                
                new_node(&((yyval._Type_defdata).ast_node));
                (yyval._Type_defdata).ast_node->type = e_defdata_ident;
                set_node_val_str((yyval._Type_defdata).ast_node, "Defdata");
                add_son_node((yyval._Type_defdata).ast_node,(yyvsp[0]._Type_defdata).ast_node);
                
                fflag=1;
                (yyval._Type_defdata).place = entry(str1);
                if ((yyvsp[0]._Type_defdata).place!=0) (yyval._Type_defdata).isarray=1; else (yyval._Type_defdata).isarray=0;
                /*printf("Dget %d %s %d\n",$$.place,str1,$$.isarray);*/
                
                /*unfinished*/
            }
#line 1687 "calculator_yacc.c"
    break;

  case 14:
#line 284 "calculator.y"
            {
                new_node(&((yyval._Type_defdata).ast_node));
                (yyval._Type_defdata).ast_node->type = e_defdata_ident;
                set_node_val_str((yyval._Type_defdata).ast_node, "Defdata*");

                (yyval._Type_defdata).place = entry(str1);
                (yyval._Type_defdata).isarray=2;
                
            }
#line 1701 "calculator_yacc.c"
    break;

  case 15:
#line 294 "calculator.y"
            {
                new_node(&((yyval._Type_idtail).ast_node));
                (yyval._Type_idtail).ast_node->type = e_idtail;
                set_node_val_str((yyval._Type_idtail).ast_node, "Idtail");
                
                add_son_node((yyval._Type_idtail).ast_node,(yyvsp[-1]._Type_defdata).ast_node);
                add_son_node((yyval._Type_idtail).ast_node,(yyvsp[0]._Type_deflist).ast_node);
                
                (yyval._Type_idtail).length=(yyvsp[0]._Type_deflist).length;
                for (int i=1;i<=(yyvsp[0]._Type_deflist).length;i++)
                {
                    (yyval._Type_idtail).place[i]=(yyvsp[0]._Type_deflist).place[i];
                    (yyval._Type_idtail).isarray[i]=(yyvsp[0]._Type_deflist).isarray[i];
                }

                (yyval._Type_idtail).varplace=(yyvsp[-1]._Type_defdata).place;/*0=null else num's place*/
                
            }
#line 1724 "calculator_yacc.c"
    break;

  case 16:
#line 313 "calculator.y"
            {
                new_node(&((yyval._Type_idtail).ast_node));
                (yyval._Type_idtail).ast_node->type = e_idtail;
                set_node_val_str((yyval._Type_idtail).ast_node, "Idtail");
                
                add_son_node((yyval._Type_idtail).ast_node,(yyvsp[-2]._Type).ast_node);
                add_brother_node((yyvsp[-2]._Type).ast_node,(yyvsp[0]._Type).ast_node);

                (yyval._Type_idtail).length=0;
                (yyval._Type_idtail).varplace=0;
            }
#line 1740 "calculator_yacc.c"
    break;

  case 17:
#line 325 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_para;
                set_node_val_str((yyval._Type).ast_node, "Para");   
            }
#line 1750 "calculator_yacc.c"
    break;

  case 18:
#line 331 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_para;
                set_node_val_str((yyval._Type).ast_node, "Para");
                add_son_node((yyval._Type).ast_node,(yyvsp[-1]._Type).ast_node);
                add_son_node((yyval._Type).ast_node,(yyvsp[0]._Type).ast_node);
            }
#line 1762 "calculator_yacc.c"
    break;

  case 19:
#line 339 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_sononearg;
                set_node_val_str((yyval._Type).ast_node, "Sononearg");
            }
#line 1772 "calculator_yacc.c"
    break;

  case 20:
#line 345 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_sononearg;
                set_node_val_str((yyval._Type).ast_node, "Sononearg");
                add_son_node((yyval._Type).ast_node,(yyvsp[-1]._Type).ast_node);
                add_son_node((yyval._Type).ast_node,(yyvsp[0]._Type).ast_node);
            }
#line 1784 "calculator_yacc.c"
    break;

  case 21:
#line 353 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_onepara;
                set_node_val_str((yyval._Type).ast_node, "Onepara");
                add_son_node((yyval._Type).ast_node,(yyvsp[-1]._Type).ast_node);
                add_son_node((yyval._Type).ast_node,(yyvsp[0]._Type_defdata).ast_node);
                
                if ((yyvsp[0]._Type_defdata).isarray==0)
                        set_valist_type((yyvsp[0]._Type_defdata).place,(yyvsp[0]._Type_defdata).place,(yyvsp[-1]._Type).Iv);
                else if ((yyvsp[0]._Type_defdata).isarray==1) set_valist_type((yyvsp[0]._Type_defdata).place,(yyvsp[0]._Type_defdata).place,2);
                else if ((yyvsp[0]._Type_defdata).isarray==2) set_valist_type((yyvsp[0]._Type_defdata).place,(yyvsp[0]._Type_defdata).place,3);
                
            }
#line 1802 "calculator_yacc.c"
    break;

  case 22:
#line 367 "calculator.y"
            {
                new_node(&((yyval._Type_defdata).ast_node));
                (yyval._Type_defdata).ast_node->type = e_paradata;
                set_node_val_str((yyval._Type_defdata).ast_node, "paradata*");
                
                fflag=1;
                (yyval._Type_defdata).place = entry(str1);
                (yyval._Type_defdata).isarray = 2;
                set_valist_cat((yyval._Type_defdata).place,(yyval._Type_defdata).place,4);
            }
#line 1817 "calculator_yacc.c"
    break;

  case 23:
#line 378 "calculator.y"
            {
                new_node(&((yyval._Type_defdata).ast_node));
                (yyval._Type_defdata).ast_node->type = e_paradata;
                set_node_val_str((yyval._Type_defdata).ast_node, "paradata");
                add_son_node((yyval._Type_defdata).ast_node,(yyvsp[0]._Type_defdata).ast_node);

                fflag=1;
                (yyval._Type_defdata).place = entry(str1);
                (yyval._Type_defdata).isarray = (yyvsp[0]._Type_defdata).isarray;
                set_valist_cat((yyval._Type_defdata).place,(yyval._Type_defdata).place,4);    
                
            }
#line 1834 "calculator_yacc.c"
    break;

  case 24:
#line 391 "calculator.y"
                {
                    new_node(&((yyval._Type_defdata).ast_node));
                    (yyval._Type_defdata).ast_node->type = e_paradatatail;
                    set_node_val_str((yyval._Type_defdata).ast_node, "paradatatail");
                    add_son_node((yyval._Type_defdata).ast_node,(yyvsp[0]._Type_defdata).ast_node);
                    (yyval._Type_defdata).isarray=1;
                }
#line 1846 "calculator_yacc.c"
    break;

  case 25:
#line 399 "calculator.y"
                {
                    new_node(&((yyval._Type_defdata).ast_node));
                    (yyval._Type_defdata).ast_node->type = e_paradatatail;
                    set_node_val_str((yyval._Type_defdata).ast_node, "paradatatail");
                    add_son_node((yyval._Type_defdata).ast_node,(yyvsp[0]._Type_defdata).ast_node);

                    (yyval._Type_defdata).isarray=(yyvsp[0]._Type_defdata).isarray;
                }
#line 1859 "calculator_yacc.c"
    break;

  case 26:
#line 408 "calculator.y"
                {
                    new_node(&((yyval._Type_defdata).ast_node));
                    (yyval._Type_defdata).ast_node->type = e_son_paradatail;
                    set_node_val_str((yyval._Type_defdata).ast_node, "Sonparadatatail");
                    
                }
#line 1870 "calculator_yacc.c"
    break;

  case 27:
#line 415 "calculator.y"
                {
                    new_node(&((yyval._Type_defdata).ast_node));
                    (yyval._Type_defdata).ast_node->type = e_son_paradatail;
                    set_node_val_str((yyval._Type_defdata).ast_node, "Sonparadatatail");
                    add_son_node((yyval._Type_defdata).ast_node,(yyvsp[0]._Type_defdata).ast_node);

                    (yyval._Type_defdata).place=entry(str2);
                    set_valist_type((yyval._Type_defdata).place,(yyval._Type_defdata).place,0);
                    set_valist_cat((yyval._Type_defdata).place,(yyval._Type_defdata).place,3);

                    (yyval._Type_defdata).isarray=1;
                }
#line 1887 "calculator_yacc.c"
    break;

  case 28:
#line 428 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_functail;
                set_node_val_str((yyval._Type).ast_node, "Functail");
                add_son_node((yyval._Type).ast_node,(yyvsp[0]._Type_midexpr).ast_node);
               
            }
#line 1899 "calculator_yacc.c"
    break;

  case 29:
#line 436 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_functail;
                set_node_val_str((yyval._Type).ast_node, "Functail");
            }
#line 1909 "calculator_yacc.c"
    break;

  case 30:
#line 442 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_block;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Block");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                
                (yyval._Type_midexpr).place=(yyvsp[-1]._Type_midexpr).place;
                (yyval._Type_midexpr).startNXQ=(yyvsp[-1]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=(yyvsp[-1]._Type_midexpr).endNXQ;
                /*printf("Bloack : %d %d\n",$2.startNXQ,$2.endNXQ);*/
            }
#line 1925 "calculator_yacc.c"
    break;

  case 31:
#line 454 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_subprogram;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Subprogram");
                
                (yyval._Type_midexpr).startNXQ=0;
                (yyval._Type_midexpr).endNXQ=0;
            }
#line 1938 "calculator_yacc.c"
    break;

  case 32:
#line 463 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_subprogram;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Subprogram");
                
                struct node *last=get_last_node((yyvsp[-1]._Type_midexpr).ast_node);
                add_brother_node(last,(yyvsp[0]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                
                (yyval._Type_midexpr).place=(yyvsp[-1]._Type_midexpr).place;
                if ((yyval._Type_midexpr).startNXQ==0) 
                        (yyval._Type_midexpr).startNXQ=(yyvsp[0]._Type_midexpr).startNXQ; 
                else    (yyval._Type_midexpr).startNXQ=(yyvsp[-1]._Type_midexpr).startNXQ;
                if ((yyvsp[0]._Type_midexpr).endNXQ!=0) 
                        (yyval._Type_midexpr).endNXQ=(yyvsp[0]._Type_midexpr).endNXQ;
                else    (yyval._Type_midexpr).endNXQ=(yyvsp[-1]._Type_midexpr).endNXQ;
            }
#line 1960 "calculator_yacc.c"
    break;

  case 33:
#line 481 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_onestatment_localdef;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Onestatement");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_localdef).ast_node);
                
                (yyval._Type_midexpr).startNXQ=0;
                (yyval._Type_midexpr).endNXQ=0;
            }
#line 1974 "calculator_yacc.c"
    break;

  case 34:
#line 491 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_onestatment_statement;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Onestatement");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);
                
                (yyval._Type_midexpr).place=(yyvsp[0]._Type_midexpr).place;
                (yyval._Type_midexpr).startNXQ=(yyvsp[0]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=(yyvsp[0]._Type_midexpr).endNXQ;
            }
#line 1989 "calculator_yacc.c"
    break;

  case 35:
#line 502 "calculator.y"
            {
                new_node(&((yyval._Type_localdef).ast_node));
                (yyval._Type_localdef).ast_node->type = e_localdef;
                set_node_val_str((yyval._Type_localdef).ast_node, "Localdef");
                add_son_node((yyval._Type_localdef).ast_node,(yyvsp[-2]._Type).ast_node);
                add_son_node((yyval._Type_localdef).ast_node,(yyvsp[-1]._Type_defdata).ast_node);
                add_son_node((yyval._Type_localdef).ast_node,(yyvsp[0]._Type_deflist).ast_node);

                (yyval._Type_localdef).startplace=(yyvsp[-1]._Type_defdata).place;
                if ((yyvsp[-1]._Type_defdata).isarray==0)
                        set_valist_type((yyvsp[-1]._Type_defdata).place,(yyvsp[-1]._Type_defdata).place,(yyvsp[-2]._Type).Iv);
                else if ((yyvsp[-1]._Type_defdata).isarray==1) set_valist_type((yyvsp[-1]._Type_defdata).place,(yyvsp[-1]._Type_defdata).place,2);
                else if ((yyvsp[-1]._Type_defdata).isarray==2) set_valist_type((yyvsp[-1]._Type_defdata).place,(yyvsp[-1]._Type_defdata).place,3);
                for (int i=1;i<=(yyvsp[0]._Type_deflist).length;i++)
                {
                    if ((yyvsp[0]._Type_deflist).isarray[i]==0)
                        set_valist_type((yyvsp[0]._Type_deflist).place[i],(yyvsp[0]._Type_deflist).place[i],(yyvsp[-2]._Type).Iv);
                    else if ((yyvsp[0]._Type_deflist).isarray[i]==1) set_valist_type((yyvsp[0]._Type_deflist).place[i],(yyvsp[0]._Type_deflist).place[i],2);
                    else if ((yyvsp[0]._Type_deflist).isarray[i]==2) set_valist_type((yyvsp[0]._Type_deflist).place[i],(yyvsp[0]._Type_deflist).place[i],3);
                    set_valist_cat((yyval._Type_localdef).startplace,(yyval._Type_localdef).endplace,0);
                }
            }
#line 2016 "calculator_yacc.c"
    break;

  case 36:
#line 525 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_statement_whilestat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Statement");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);
                
                (yyval._Type_midexpr).place=(yyvsp[0]._Type_midexpr).place;
                (yyval._Type_midexpr).startNXQ=(yyvsp[0]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=(yyvsp[0]._Type_midexpr).endNXQ;
            }
#line 2031 "calculator_yacc.c"
    break;

  case 37:
#line 536 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_statement_breakstat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Statement");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);

                (yyval._Type_midexpr).place=(yyvsp[0]._Type_midexpr).place;
                (yyval._Type_midexpr).startNXQ=(yyvsp[0]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=(yyvsp[0]._Type_midexpr).endNXQ;
            }
#line 2046 "calculator_yacc.c"
    break;

  case 38:
#line 547 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_statement_continuestat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Statement");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);

                (yyval._Type_midexpr).place=(yyvsp[0]._Type_midexpr).place;
                (yyval._Type_midexpr).startNXQ=(yyvsp[0]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=(yyvsp[0]._Type_midexpr).endNXQ;
            }
#line 2061 "calculator_yacc.c"
    break;

  case 39:
#line 558 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_statement_blockstat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Statement");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);

                (yyval._Type_midexpr).place=(yyvsp[0]._Type_midexpr).place;
                (yyval._Type_midexpr).startNXQ=(yyvsp[0]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=(yyvsp[0]._Type_midexpr).endNXQ;
            }
#line 2076 "calculator_yacc.c"
    break;

  case 40:
#line 569 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_statement_emptystat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Statement");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type).ast_node);
                
            }
#line 2088 "calculator_yacc.c"
    break;

  case 41:
#line 577 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_statement_assignstat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Statement");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);
                
                (yyval._Type_midexpr).place=(yyvsp[0]._Type_midexpr).place;
                (yyval._Type_midexpr).startNXQ=(yyvsp[0]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=(yyvsp[0]._Type_midexpr).endNXQ;
            }
#line 2103 "calculator_yacc.c"
    break;

  case 42:
#line 588 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_statement_returnstat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Statement");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type).ast_node);
            }
#line 2114 "calculator_yacc.c"
    break;

  case 43:
#line 595 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_statement_ifstat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Statement");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);
                
                (yyval._Type_midexpr).place=(yyvsp[0]._Type_midexpr).place;
                (yyval._Type_midexpr).startNXQ=(yyvsp[0]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=(yyvsp[0]._Type_midexpr).endNXQ;
            }
#line 2129 "calculator_yacc.c"
    break;

  case 44:
#line 606 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_ifstat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Ifstat");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[-3]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);

                if ((yyvsp[0]._Type_midexpr).startNXQ!=0)
                    {
                        insertNXQ((yyvsp[-1]._Type_midexpr).startNXQ,"j=",(yyvsp[-3]._Type_midexpr).place,'0',(yyvsp[0]._Type_midexpr).startNXQ+2); 
                        insertNXQ((yyvsp[-1]._Type_midexpr).endNXQ+2,"j",0,0,NXQ+1);
                    }
                else 
                    {
                        insertNXQ((yyvsp[-1]._Type_midexpr).startNXQ,"j=",(yyvsp[-3]._Type_midexpr).place,'0',NXQ+1); 
                    }
                (yyval._Type_midexpr).startNXQ=(yyvsp[-3]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=NXQ-1;
                /*insert newqlist*/
            }
#line 2155 "calculator_yacc.c"
    break;

  case 45:
#line 628 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_elsestat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Elsestat");
                
                (yyval._Type_midexpr).startNXQ=0;
                (yyval._Type_midexpr).endNXQ=0;
            }
#line 2168 "calculator_yacc.c"
    break;

  case 46:
#line 637 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_elsestat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Elsestat");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);
                
                (yyval._Type_midexpr).startNXQ=(yyvsp[0]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=(yyvsp[0]._Type_midexpr).endNXQ;
                
            }
#line 2183 "calculator_yacc.c"
    break;

  case 47:
#line 648 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_whilestat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Whilestat");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[-2]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);

                insertNXQ((yyvsp[0]._Type_midexpr).startNXQ,"j=",(yyvsp[-2]._Type_midexpr).place,'0',(yyvsp[0]._Type_midexpr).endNXQ+3);
                insertNXQ((yyvsp[0]._Type_midexpr).endNXQ+2,"j",0,0,(yyvsp[-2]._Type_midexpr).startNXQ);
                (yyval._Type_midexpr).startNXQ=(yyvsp[-2]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=NXQ-1;
                
                conti_update_Quterlist((yyval._Type_midexpr).startNXQ,(yyval._Type_midexpr).endNXQ);
               
            }
#line 2203 "calculator_yacc.c"
    break;

  case 48:
#line 664 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_returnstat;
                set_node_val_str((yyval._Type).ast_node, "Returnstat");
                add_son_node((yyval._Type).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
            }
#line 2214 "calculator_yacc.c"
    break;

  case 49:
#line 671 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_breakstat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Breakstat");

                (yyval._Type_midexpr).startNXQ=NXQ;
                (yyval._Type_midexpr).endNXQ=NXQ;
                insertNXQ(NXQ,"j",0,0,NXQ);
                setbreakflag((yyval._Type_midexpr).startNXQ);
            }
#line 2229 "calculator_yacc.c"
    break;

  case 50:
#line 682 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_continuestat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Continuestat");
                
                (yyval._Type_midexpr).startNXQ=NXQ;
                (yyval._Type_midexpr).endNXQ=NXQ;
                insertNXQ(NXQ,"j",0,0,NXQ);
                setcontinueflag((yyval._Type_midexpr).startNXQ);
            }
#line 2244 "calculator_yacc.c"
    break;

  case 51:
#line 693 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_blockstat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Blockstat");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);

                (yyval._Type_midexpr).place=(yyvsp[0]._Type_midexpr).place;
                (yyval._Type_midexpr).startNXQ=(yyvsp[0]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=(yyvsp[0]._Type_midexpr).endNXQ;
            }
#line 2259 "calculator_yacc.c"
    break;

  case 52:
#line 704 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_emptystat;
                set_node_val_str((yyval._Type).ast_node, "Emptystat");
                

            }
#line 2271 "calculator_yacc.c"
    break;

  case 53:
#line 712 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_assignstat;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Assignstat");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                
                (yyval._Type_midexpr).place=(yyvsp[-1]._Type_midexpr).place;
                (yyval._Type_midexpr).startNXQ=(yyvsp[-1]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=(yyvsp[-1]._Type_midexpr).endNXQ;
                /*printf("Assignstat :%d %d\n",$$.startNXQ,$$.endNXQ);*/
            }
#line 2287 "calculator_yacc.c"
    break;

  case 54:
#line 724 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_altexpr;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Altexpr");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);
                
                (yyval._Type_midexpr).place=(yyvsp[0]._Type_midexpr).place;
                (yyval._Type_midexpr).startNXQ=(yyvsp[0]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=(yyvsp[0]._Type_midexpr).endNXQ;
            }
#line 2302 "calculator_yacc.c"
    break;

  case 55:
#line 735 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_expr;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Expr");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);

                (yyval._Type_midexpr).place=(yyvsp[0]._Type_midexpr).place;
                (yyval._Type_midexpr).startNXQ=(yyvsp[0]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=(yyvsp[0]._Type_midexpr).endNXQ;
            }
#line 2317 "calculator_yacc.c"
    break;

  case 56:
#line 746 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_assexpr;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Assexpr");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_itemtail).ast_node);

                (yyval._Type_midexpr).place=(yyvsp[-1]._Type_midexpr).place;    
                (yyval._Type_midexpr).startNXQ=(yyvsp[-1]._Type_midexpr).startNXQ;
                for (int i=(yyvsp[0]._Type_itemtail).length;i>=1;i--)
                {
                    (yyval._Type_midexpr).endNXQ=NXQ;
                    UpdateQlist((yyvsp[0]._Type_itemtail).op[i],(yyvsp[0]._Type_itemtail).place[i],0,(yyval._Type_midexpr).place,2);
                }
            }
#line 2337 "calculator_yacc.c"
    break;

  case 57:
#line 762 "calculator.y"
            {
                new_node(&((yyval._Type_itemtail).ast_node));
                (yyval._Type_itemtail).ast_node->type = e_asstail;
                set_node_val_str((yyval._Type_itemtail).ast_node, "Asstail");

                (yyval._Type_itemtail).length=0;
            }
#line 2349 "calculator_yacc.c"
    break;

  case 58:
#line 770 "calculator.y"
            {
                new_node(&((yyval._Type_itemtail).ast_node));
                (yyval._Type_itemtail).ast_node->type = e_asstail;
                set_node_val_str((yyval._Type_itemtail).ast_node, "Asstail");
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[0]._Type_itemtail).ast_node);

                (yyval._Type_itemtail).length=(yyvsp[0]._Type_itemtail).length+1;
                strcpy((yyval._Type_itemtail).op[(yyval._Type_itemtail).length],"=");
                (yyval._Type_itemtail).place[(yyval._Type_itemtail).length]=(yyvsp[-1]._Type_midexpr).place;

                for (int i=1;i<=(yyvsp[0]._Type_itemtail).length;i++)
                {
                    strcpy((yyval._Type_itemtail).op[i],(yyvsp[0]._Type_itemtail).op[i]);
                    (yyval._Type_itemtail).place[i]=(yyvsp[0]._Type_itemtail).place[i];
                }
            }
#line 2371 "calculator_yacc.c"
    break;

  case 59:
#line 788 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_orexpr;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Orexpr");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_itemtail).ast_node);

                (yyval._Type_midexpr).place=(yyvsp[-1]._Type_midexpr).place;    
                (yyval._Type_midexpr).startNXQ=(yyvsp[-1]._Type_midexpr).startNXQ; 
                for (int i=(yyvsp[0]._Type_itemtail).length;i>=1;i--)
                {
                    int newplace=newtemp();
                    (yyval._Type_midexpr).endNXQ=NXQ;
                    UpdateQlist((yyvsp[0]._Type_itemtail).op[i],(yyval._Type_midexpr).place,(yyvsp[0]._Type_itemtail).place[i],newplace,2);
                    (yyval._Type_midexpr).place=newplace;
                }
            }
#line 2393 "calculator_yacc.c"
    break;

  case 60:
#line 806 "calculator.y"
            {
                new_node(&((yyval._Type_itemtail).ast_node));
                (yyval._Type_itemtail).ast_node->type = e_ortail;
                set_node_val_str((yyval._Type_itemtail).ast_node, "Ortail");

                (yyval._Type_itemtail).length=0;
            }
#line 2405 "calculator_yacc.c"
    break;

  case 61:
#line 814 "calculator.y"
            {
                new_node(&((yyval._Type_itemtail).ast_node));
                (yyval._Type_itemtail).ast_node->type = e_ortail;
                set_node_val_str((yyval._Type_itemtail).ast_node, "Ortail");
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[0]._Type_itemtail).ast_node);

                (yyval._Type_itemtail).length=(yyvsp[0]._Type_itemtail).length+1;
                strcpy((yyval._Type_itemtail).op[(yyval._Type_itemtail).length],"||");
                (yyval._Type_itemtail).place[(yyval._Type_itemtail).length]=(yyvsp[-1]._Type_midexpr).place;

                for (int i=1;i<=(yyvsp[0]._Type_itemtail).length;i++)
                {
                    strcpy((yyval._Type_itemtail).op[i],(yyvsp[0]._Type_itemtail).op[i]);
                    (yyval._Type_itemtail).place[i]=(yyvsp[0]._Type_itemtail).place[i];
                }
            }
#line 2427 "calculator_yacc.c"
    break;

  case 62:
#line 832 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_andexpr;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Andexpr");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_itemtail).ast_node);

                (yyval._Type_midexpr).place=(yyvsp[-1]._Type_midexpr).place;   
                (yyval._Type_midexpr).startNXQ=(yyvsp[-1]._Type_midexpr).startNXQ; 
                for (int i=(yyvsp[0]._Type_itemtail).length;i>=1;i--)
                {
                    int newplace=newtemp();
                    (yyval._Type_midexpr).endNXQ=NXQ;
                    UpdateQlist((yyvsp[0]._Type_itemtail).op[i],(yyval._Type_midexpr).place,(yyvsp[0]._Type_itemtail).place[i],newplace,2);
                    (yyval._Type_midexpr).place=newplace;
                }
            }
#line 2449 "calculator_yacc.c"
    break;

  case 63:
#line 850 "calculator.y"
            {
                new_node(&((yyval._Type_itemtail).ast_node));
                (yyval._Type_itemtail).ast_node->type = e_andtail;
                set_node_val_str((yyval._Type_itemtail).ast_node, "Andtail");
                
                (yyval._Type_itemtail).length=0;
            }
#line 2461 "calculator_yacc.c"
    break;

  case 64:
#line 858 "calculator.y"
            {
                new_node(&((yyval._Type_itemtail).ast_node));
                (yyval._Type_itemtail).ast_node->type = e_andtail;
                set_node_val_str((yyval._Type_itemtail).ast_node, "Andtail");
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[0]._Type_itemtail).ast_node);
                
                (yyval._Type_itemtail).length=(yyvsp[0]._Type_itemtail).length+1;
                strcpy((yyval._Type_itemtail).op[(yyval._Type_itemtail).length],"&&");
                (yyval._Type_itemtail).place[(yyval._Type_itemtail).length]=(yyvsp[-1]._Type_midexpr).place;

                for (int i=1;i<=(yyvsp[0]._Type_itemtail).length;i++)
                {
                    strcpy((yyval._Type_itemtail).op[i],(yyvsp[0]._Type_itemtail).op[i]);
                    (yyval._Type_itemtail).place[i]=(yyvsp[0]._Type_itemtail).place[i];
                }
            }
#line 2483 "calculator_yacc.c"
    break;

  case 65:
#line 876 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_cmpexpr;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Cmpexpr");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_itemtail).ast_node);

                (yyval._Type_midexpr).place=(yyvsp[-1]._Type_midexpr).place;    
                (yyval._Type_midexpr).startNXQ=(yyvsp[-1]._Type_midexpr).startNXQ;
                for (int i=(yyvsp[0]._Type_itemtail).length;i>=1;i--)
                {
                    int newplace=newtemp();
                    (yyval._Type_midexpr).endNXQ=NXQ;
                    UpdateQlist((yyvsp[0]._Type_itemtail).op[i],(yyval._Type_midexpr).place,(yyvsp[0]._Type_itemtail).place[i],newplace,2);
                    (yyval._Type_midexpr).place=newplace;
                }
            }
#line 2505 "calculator_yacc.c"
    break;

  case 66:
#line 894 "calculator.y"
            {
                new_node(&((yyval._Type_itemtail).ast_node));
                (yyval._Type_itemtail).ast_node->type = e_cmptail;
                set_node_val_str((yyval._Type_itemtail).ast_node, "Cmptail");
                
                (yyval._Type_itemtail).length=0;
            }
#line 2517 "calculator_yacc.c"
    break;

  case 67:
#line 902 "calculator.y"
            {
                new_node(&((yyval._Type_itemtail).ast_node));
                (yyval._Type_itemtail).ast_node->type = e_cmptail;
                set_node_val_str((yyval._Type_itemtail).ast_node, "Cmptail");
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[-2]._Type_rop).ast_node);
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[0]._Type_itemtail).ast_node);

                (yyval._Type_itemtail).length=(yyvsp[0]._Type_itemtail).length+1;
                strcpy((yyval._Type_itemtail).op[(yyval._Type_itemtail).length],(yyvsp[-2]._Type_rop).op);
                (yyval._Type_itemtail).place[(yyval._Type_itemtail).length]=(yyvsp[-1]._Type_midexpr).place;

                for (int i=1;i<=(yyvsp[0]._Type_itemtail).length;i++)
                {
                    strcpy((yyval._Type_itemtail).op[i],(yyvsp[0]._Type_itemtail).op[i]);
                    (yyval._Type_itemtail).place[i]=(yyvsp[0]._Type_itemtail).place[i];
                }
            }
#line 2540 "calculator_yacc.c"
    break;

  case 68:
#line 921 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_cmps;
                set_node_val_str((yyval._Type_rop).ast_node, "Cmps");

                strcpy((yyval._Type_rop).op,">=");
            }
#line 2552 "calculator_yacc.c"
    break;

  case 69:
#line 929 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_cmps;
                set_node_val_str((yyval._Type_rop).ast_node, "Cmps");

                strcpy((yyval._Type_rop).op,">");
            }
#line 2564 "calculator_yacc.c"
    break;

  case 70:
#line 937 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_cmps;
                set_node_val_str((yyval._Type_rop).ast_node, "Cmps");

                strcpy((yyval._Type_rop).op,"<");
            }
#line 2576 "calculator_yacc.c"
    break;

  case 71:
#line 945 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_cmps;
                set_node_val_str((yyval._Type_rop).ast_node, "Cmps");

                strcpy((yyval._Type_rop).op,"<=");
            }
#line 2588 "calculator_yacc.c"
    break;

  case 72:
#line 953 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_cmps;
                set_node_val_str((yyval._Type_rop).ast_node, "Cmps");

                strcpy((yyval._Type_rop).op,"==");
            }
#line 2600 "calculator_yacc.c"
    break;

  case 73:
#line 961 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_cmps;
                set_node_val_str((yyval._Type_rop).ast_node, "Cmps");

                strcpy((yyval._Type_rop).op,"!=");
            }
#line 2612 "calculator_yacc.c"
    break;

  case 74:
#line 969 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_aloexpr;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Aloexpr");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_itemtail).ast_node);

                (yyval._Type_midexpr).place=(yyvsp[-1]._Type_midexpr).place;   
                (yyval._Type_midexpr).startNXQ=(yyvsp[-1]._Type_midexpr).startNXQ; 
                for (int i=(yyvsp[0]._Type_itemtail).length;i>=1;i--)
                {
                    int newplace=newtemp();
                    (yyval._Type_midexpr).endNXQ=NXQ;
                    UpdateQlist((yyvsp[0]._Type_itemtail).op[i],(yyval._Type_midexpr).place,(yyvsp[0]._Type_itemtail).place[i],newplace,3);
                    (yyval._Type_midexpr).place=newplace;
                }
            }
#line 2634 "calculator_yacc.c"
    break;

  case 75:
#line 987 "calculator.y"
            {
                new_node(&((yyval._Type_itemtail).ast_node));
                (yyval._Type_itemtail).ast_node->type = e_alotail;
                set_node_val_str((yyval._Type_itemtail).ast_node, "Alotail");

                (yyval._Type_itemtail).length=0;
            }
#line 2646 "calculator_yacc.c"
    break;

  case 76:
#line 995 "calculator.y"
            {
                new_node(&((yyval._Type_itemtail).ast_node));
                (yyval._Type_itemtail).ast_node->type = e_alotail;
                set_node_val_str((yyval._Type_itemtail).ast_node, "Alotail");
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[-2]._Type_rop).ast_node);
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[0]._Type_itemtail).ast_node);
                
                (yyval._Type_itemtail).length=(yyvsp[0]._Type_itemtail).length+1;
                strcpy((yyval._Type_itemtail).op[(yyval._Type_itemtail).length],(yyvsp[-2]._Type_rop).op);
                (yyval._Type_itemtail).place[(yyval._Type_itemtail).length]=(yyvsp[-1]._Type_midexpr).place;

                for (int i=1;i<=(yyvsp[0]._Type_itemtail).length;i++)
                {
                    strcpy((yyval._Type_itemtail).op[i],(yyvsp[0]._Type_itemtail).op[i]);
                    (yyval._Type_itemtail).place[i]=(yyvsp[0]._Type_itemtail).place[i];
                }
            }
#line 2669 "calculator_yacc.c"
    break;

  case 77:
#line 1014 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_addsub;
                set_node_val_str((yyval._Type_rop).ast_node, "Addsub");

                strcpy((yyval._Type_rop).op,"+");
            }
#line 2681 "calculator_yacc.c"
    break;

  case 78:
#line 1022 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_addsub;
                set_node_val_str((yyval._Type_rop).ast_node, "Addsub");
                
                strcpy((yyval._Type_rop).op,"-");
            }
#line 2693 "calculator_yacc.c"
    break;

  case 79:
#line 1030 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_item;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Item");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_itemtail).ast_node);

                (yyval._Type_midexpr).place=(yyvsp[-1]._Type_midexpr).place;
                (yyval._Type_midexpr).startNXQ=(yyvsp[-1]._Type_midexpr).startNXQ;    
                for (int i=(yyvsp[0]._Type_itemtail).length;i>=1;i--)
                {
                    int newplace=newtemp();
                    //printf("Item : %d %s %d %d %d",i,$2.op[i],$$.place,$2.place[i],newplace);
                    (yyval._Type_midexpr).endNXQ=NXQ;
                    UpdateQlist((yyvsp[0]._Type_itemtail).op[i],(yyval._Type_midexpr).place,(yyvsp[0]._Type_itemtail).place[i],newplace,4);
                    (yyval._Type_midexpr).place=newplace;
                }
            }
#line 2716 "calculator_yacc.c"
    break;

  case 80:
#line 1049 "calculator.y"
            {
                new_node(&((yyval._Type_itemtail).ast_node));
                (yyval._Type_itemtail).ast_node->type = e_itemtail;
                set_node_val_str((yyval._Type_itemtail).ast_node, "Itemtail");
                
                (yyval._Type_itemtail).length=0;

            }
#line 2729 "calculator_yacc.c"
    break;

  case 81:
#line 1058 "calculator.y"
            {
                new_node(&((yyval._Type_itemtail).ast_node));
                (yyval._Type_itemtail).ast_node->type = e_itemtail;
                set_node_val_str((yyval._Type_itemtail).ast_node, "Itemtail");
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[-2]._Type_rop).ast_node);
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
                add_son_node((yyval._Type_itemtail).ast_node,(yyvsp[0]._Type_itemtail).ast_node);
                
                (yyval._Type_itemtail).length=(yyvsp[0]._Type_itemtail).length+1;
                strcpy((yyval._Type_itemtail).op[(yyval._Type_itemtail).length],(yyvsp[-2]._Type_rop).op);
                (yyval._Type_itemtail).place[(yyval._Type_itemtail).length]=(yyvsp[-1]._Type_midexpr).place;
                
                for (int i=1;i<=(yyvsp[0]._Type_itemtail).length;i++)
                {
                    strcpy((yyval._Type_itemtail).op[i],(yyvsp[0]._Type_itemtail).op[i]);
                    (yyval._Type_itemtail).place[i]=(yyvsp[0]._Type_itemtail).place[i];
                }
                
            }
#line 2753 "calculator_yacc.c"
    break;

  case 82:
#line 1078 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_muldiv;
                set_node_val_str((yyval._Type_rop).ast_node, "Muldiv");

                strcpy((yyval._Type_rop).op,"*");
            }
#line 2765 "calculator_yacc.c"
    break;

  case 83:
#line 1086 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_muldiv;
                set_node_val_str((yyval._Type_rop).ast_node, "Muldiv");

                strcpy((yyval._Type_rop).op,"/");
            }
#line 2777 "calculator_yacc.c"
    break;

  case 84:
#line 1094 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_factor;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Factor");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[-1]._Type_rop).ast_node);
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);

                (yyval._Type_midexpr).place=newtemp();
                (yyval._Type_midexpr).startNXQ=(yyvsp[0]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=NXQ;
                UpdateQlist((yyvsp[-1]._Type_rop).op,(yyvsp[0]._Type_midexpr).place,0,(yyval._Type_midexpr).place,5);
                
            }
#line 2795 "calculator_yacc.c"
    break;

  case 85:
#line 1108 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_factor;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Factor");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_midexpr).ast_node);
                
                (yyval._Type_midexpr).place=(yyvsp[0]._Type_midexpr).place;
                (yyval._Type_midexpr).startNXQ=(yyvsp[0]._Type_midexpr).startNXQ;
                (yyval._Type_midexpr).endNXQ=(yyvsp[0]._Type_midexpr).endNXQ;
            }
#line 2810 "calculator_yacc.c"
    break;

  case 86:
#line 1119 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_lop;
                set_node_val_str((yyval._Type_rop).ast_node, "Lop");
                
                strcpy((yyval._Type_rop).op,"!");
                
            }
#line 2823 "calculator_yacc.c"
    break;

  case 87:
#line 1128 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_lop;
                set_node_val_str((yyval._Type_rop).ast_node, "Lop");

                strcpy((yyval._Type_rop).op,"-");
            }
#line 2835 "calculator_yacc.c"
    break;

  case 88:
#line 1136 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_lop;
                set_node_val_str((yyval._Type_rop).ast_node, "Lop");

                strcpy((yyval._Type_rop).op,"&");
            }
#line 2847 "calculator_yacc.c"
    break;

  case 89:
#line 1144 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_lop;
                set_node_val_str((yyval._Type_rop).ast_node, "Lop");

                strcpy((yyval._Type_rop).op,"*");
            }
#line 2859 "calculator_yacc.c"
    break;

  case 90:
#line 1152 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_lop;
                set_node_val_str((yyval._Type_rop).ast_node, "Lop");
                add_son_node((yyval._Type_rop).ast_node,(yyvsp[0]._Type).ast_node);

                strcpy((yyval._Type_rop).op,"++");
            }
#line 2872 "calculator_yacc.c"
    break;

  case 91:
#line 1161 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_lop;
                set_node_val_str((yyval._Type_rop).ast_node, "Lop");
                add_son_node((yyval._Type_rop).ast_node,(yyvsp[0]._Type).ast_node);

                strcpy((yyval._Type_rop).op,"--");
            }
#line 2885 "calculator_yacc.c"
    break;

  case 92:
#line 1170 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_val;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Val");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_defdata).ast_node);
                
                (yyval._Type_midexpr).place=(yyvsp[0]._Type_defdata).place;
                (yyval._Type_midexpr).startNXQ=NXQ;
                (yyval._Type_midexpr).endNXQ=0;
            }
#line 2900 "calculator_yacc.c"
    break;

  case 93:
#line 1181 "calculator.y"
            {
                new_node(&((yyval._Type_midexpr).ast_node));
                (yyval._Type_midexpr).ast_node->type = e_val;
                set_node_val_str((yyval._Type_midexpr).ast_node, "Val");
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[-1]._Type_defdata).ast_node);
                add_son_node((yyval._Type_midexpr).ast_node,(yyvsp[0]._Type_rop).ast_node);
                
                if (Valist[(yyvsp[-1]._Type_defdata).place].cat==1) (yyval._Type_midexpr).place=newtemp();
                else (yyval._Type_midexpr).place=(yyvsp[-1]._Type_defdata).place;
                (yyval._Type_midexpr).startNXQ=NXQ;
                (yyval._Type_midexpr).endNXQ=NXQ;
                UpdateQlist((yyvsp[0]._Type_rop).op,(yyvsp[-1]._Type_defdata).place,0,(yyval._Type_midexpr).place,6);
                
            }
#line 2919 "calculator_yacc.c"
    break;

  case 94:
#line 1196 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_rop;
                set_node_val_str((yyval._Type_rop).ast_node, "Rop");
                add_son_node((yyval._Type_rop).ast_node,(yyvsp[0]._Type).ast_node);
                strcpy((yyval._Type_rop).op,"++");
                /*printf("ROP2 : %s\n",$$.op);*/
            }
#line 2932 "calculator_yacc.c"
    break;

  case 95:
#line 1205 "calculator.y"
            {
                new_node(&((yyval._Type_rop).ast_node));
                (yyval._Type_rop).ast_node->type = e_rop;
                set_node_val_str((yyval._Type_rop).ast_node, "Rop");
                add_son_node((yyval._Type_rop).ast_node,(yyvsp[0]._Type).ast_node);
                strcpy((yyval._Type_rop).op,"--");
                /*printf("ROP3 : %s\n",$$.op);*/
            }
#line 2945 "calculator_yacc.c"
    break;

  case 96:
#line 1214 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_incr;
                set_node_val_str((yyval._Type).ast_node, "Incr");
            }
#line 2955 "calculator_yacc.c"
    break;

  case 97:
#line 1220 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_decr;
                set_node_val_str((yyval._Type).ast_node, "Decr");
            }
#line 2965 "calculator_yacc.c"
    break;

  case 98:
#line 1226 "calculator.y"
            {
                new_node(&((yyval._Type_defdata).ast_node));
                (yyval._Type_defdata).ast_node->type = e_elem;
                set_node_val_str((yyval._Type_defdata).ast_node, "Elem");
                add_son_node((yyval._Type_defdata).ast_node,(yyvsp[0]._Type).ast_node);

                (yyval._Type_defdata).place=entry(str1);
            }
#line 2978 "calculator_yacc.c"
    break;

  case 99:
#line 1235 "calculator.y"
            {
                new_node(&((yyval._Type_defdata).ast_node));
                (yyval._Type_defdata).ast_node->type = e_elem;
                set_node_val_str((yyval._Type_defdata).ast_node, "Elem");
                add_son_node((yyval._Type_defdata).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);

               
            }
#line 2991 "calculator_yacc.c"
    break;

  case 100:
#line 1244 "calculator.y"
            {
                new_node(&((yyval._Type_defdata).ast_node));
                (yyval._Type_defdata).ast_node->type = e_elem;
                set_node_val_str((yyval._Type_defdata).ast_node, "Elem");
                add_son_node((yyval._Type_defdata).ast_node,(yyvsp[0]._Type_defdata).ast_node);

                (yyval._Type_defdata).place=(yyvsp[0]._Type_defdata).place;

            }
#line 3005 "calculator_yacc.c"
    break;

  case 101:
#line 1254 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_idexpr;
                set_node_val_str((yyval._Type).ast_node, "Idexpr");
            }
#line 3015 "calculator_yacc.c"
    break;

  case 102:
#line 1260 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_idexpr;
                set_node_val_str((yyval._Type).ast_node, "Idexpr");
                add_son_node((yyval._Type).ast_node,(yyvsp[-1]._Type_midexpr).ast_node);
            }
#line 3026 "calculator_yacc.c"
    break;

  case 103:
#line 1267 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_idexpr;
                set_node_val_str((yyval._Type).ast_node, "Idexpr");
                add_son_node((yyval._Type).ast_node,(yyvsp[-1]._Type).ast_node);
            }
#line 3037 "calculator_yacc.c"
    break;

  case 104:
#line 1274 "calculator.y"
            {
                new_node(&((yyval._Type_defdata).ast_node));
                (yyval._Type_defdata).ast_node->type = e_literal;
                set_node_val_str((yyval._Type_defdata).ast_node, "Literal");
                
                (yyval._Type_defdata).place=entry(str2);
                set_valist_type((yyval._Type_defdata).place,(yyval._Type_defdata).place,0);
                set_valist_cat((yyval._Type_defdata).place,(yyval._Type_defdata).place,1);
            }
#line 3051 "calculator_yacc.c"
    break;

  case 105:
#line 1284 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_realarg;
                set_node_val_str((yyval._Type).ast_node, "Realarg");
            }
#line 3061 "calculator_yacc.c"
    break;

  case 106:
#line 1290 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_realarg;
                set_node_val_str((yyval._Type).ast_node, "Realarg");
                add_son_node((yyval._Type).ast_node,(yyvsp[-1]._Type).ast_node);
                add_son_node((yyval._Type).ast_node,(yyvsp[0]._Type).ast_node);
            }
#line 3073 "calculator_yacc.c"
    break;

  case 107:
#line 1298 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_sonarg;
                set_node_val_str((yyval._Type).ast_node, "Sonarg");
            }
#line 3083 "calculator_yacc.c"
    break;

  case 108:
#line 1304 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_sonarg;
                set_node_val_str((yyval._Type).ast_node, "Sonarg");
                add_son_node((yyval._Type).ast_node,(yyvsp[-1]._Type).ast_node);
                add_son_node((yyval._Type).ast_node,(yyvsp[0]._Type).ast_node);
            }
#line 3095 "calculator_yacc.c"
    break;

  case 109:
#line 1312 "calculator.y"
            {
                new_node(&((yyval._Type).ast_node));
                (yyval._Type).ast_node->type = e_arg;
                set_node_val_str((yyval._Type).ast_node, "Arg");
            }
#line 3105 "calculator_yacc.c"
    break;


#line 3109 "calculator_yacc.c"

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
#line 1317 "calculator.y"


void yyerror(char * msg)
{
    printf("Line(%d): %s\n", line_no, msg);
}

void PreOrder(struct node *root,int tab)
{
    int i = 0;
    struct node *son = root ->son;
    if (root != NULL)
    {
        for (i = 0; i < tab - 1; ++i) {
			printf("|\t");
		}
		if (i == tab - 1) {
			printf("|-----");
		}
		printf("<%s>\n", root->val.str);
		++tab;
		while (son != NULL) {
			PreOrder(son, tab);
			son = son->next;
		}
    }
}

void Outputlist()
{
    int i=1;
    printf(" No.\t name \t\t   type\t\t cat\t\n");
    if (i>=Varcount)
    {
        printf("Symbol Table is Null!\n");
    }
    for (i=1;i<Varcount;i++)
    {
        printf("%4d\t%6s\t\t",i,Valist[i].name);
		if(Valist[i].type==0)
        {
            printf(" INTEGER\t");
		}
		else if (Valist[i].type==1)
        {
            printf(" VOID\t");
		}
        else if (Valist[i].type==2) 
            printf("INTARRAY\t"); 
            else if (Valist[i].type==3)
                printf("POINTER\t\t"); 
        else
         printf("NULL\t");
		if(Valist[i].cat==0)
            printf(" Defdata \n");
        else if (Valist[i].cat==1)
            printf("Literal Number\n");
            else if (Valist[i].cat==2)
             printf("Varrdef Number\n");
             else if (Valist[i].cat==3)
              printf("Sonparadatail\n");
                else if (Valist[i].cat==4)
                 printf("Paradata\n");
                  else if (Valist[i].cat==5)
                   printf("Def Idtail\n");
                    else if (Valist[i].cat==6)
                     printf("Def Deflist\n");
        else printf(" UNKOWN \n");
    }
}

void OutputQ()
{
    int i=1;
    if (i>=NXQ) printf("no quater exists!\n");
    for (i=1;i<NXQ;i++)
    {
        printf("(%3d) ",i);
        if (strcmp(Quaterlist[i].result,"_")==0)
            printf("(%s,  %s,  %s,  %d)\n",Quaterlist[i].op, Quaterlist[i].arg1, Quaterlist[i].arg2,Quaterlist[i].line);
        else 
            printf("(%s,  %s,  %s,  %s)\n",Quaterlist[i].op, Quaterlist[i].arg1, Quaterlist[i].arg2,Quaterlist[i].result);
    }
    
}
void UpdateQlist(char *Op,int index1,int index2,int result,int x)
{
    /*printf("\n%s %d\n",Op,x);*/
    if(strcmp(Op,"++")==0)
    {
        strcpy(Quaterlist[NXQ].op, "+");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, "1");
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"--")==0)
    {
        strcpy(Quaterlist[NXQ].op, "-");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, "1");
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"!")==0)
    {
        strcpy(Quaterlist[NXQ].op, "!");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, "_");
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"-")==0)
    {
        strcpy(Quaterlist[NXQ].op, "-");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        if (index2==0) 
            strcpy(Quaterlist[NXQ].arg2, "_");/*for lop '-' */
        else
            strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);/*for muldiv '-' */
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"*")==0)
    {
        strcpy(Quaterlist[NXQ].op, "*");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        if (index2==0) 
            strcpy(Quaterlist[NXQ].arg2, "_"); /*for lop '*' */
        else 
            strcpy(Quaterlist[NXQ].arg2, Valist[index2].name); /*for muldiv '*' */
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"&")==0)
    {
        strcpy(Quaterlist[NXQ].op, "&");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, "_");
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"/")==0)
    {
        strcpy(Quaterlist[NXQ].op, "/");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"+")==0)
    {
        strcpy(Quaterlist[NXQ].op, "+");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,">=")==0)
    {
        strcpy(Quaterlist[NXQ].op, ">=");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,">")==0)
    {
        strcpy(Quaterlist[NXQ].op, ">");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"<=")==0)
    {
        strcpy(Quaterlist[NXQ].op, "<=");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"<")==0)
    {
        strcpy(Quaterlist[NXQ].op, "<");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"==")==0)
    {
        strcpy(Quaterlist[NXQ].op, "==");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"!=")==0)
    {
        strcpy(Quaterlist[NXQ].op, "!=");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"&&")==0)
    {
        strcpy(Quaterlist[NXQ].op, "&&");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"||")==0)
    {
        strcpy(Quaterlist[NXQ].op, "||");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"=")==0)
    {
        strcpy(Quaterlist[NXQ].op, "=");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, "_");
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
}

int newtemp()/*create new temo*/
{
    tempnum++;
    char ss[5]="t";
    int t=tempnum,length=0;
    int a[4];
    while (t>0) 
    {
        a[length]=t%10;
        t=t/10;
        length++;
    }
    for (int i=length;i>0;i--)
    {
        ss[length-i+1]=(char)(48+a[i-1]);
    }
    return entry(ss);
}

int insertNXQ(int no,char *Op,int index1,int index2,int line)
{
    //insertNXQ($5.startNXQ,"j=",$3.place,'0',$6.startNXQ+1); 
    /*printf("%d %s %d %d %d\n",no,Op,index1,index2,line);*/
    OutputQ();
    /*test*/
    
    for (int i=NXQ;i>no;i--)
    {
        Quaterlist[i]=Quaterlist[i-1];
        if  (strcmp(Op,"j")==0 || strcmp(Op,"j=")==0) Quaterlist[i].line++;
    }
    if(strcmp(Op,"j=")==0)
    {
        strcpy(Quaterlist[no].op, "j=");
        strcpy(Quaterlist[no].arg1, Valist[index1].name);
        strcpy(Quaterlist[no].arg2, "0");
        strcpy(Quaterlist[no].result,"_");
        Quaterlist[no].line=line;
        Quaterlist[no].continueflag=0;
        Quaterlist[no].breakflag=0;
        NXQ++;
    }
    if(strcmp(Op,"j")==0)
    {
        strcpy(Quaterlist[no].op, "j");
        strcpy(Quaterlist[no].arg1, "_");
        strcpy(Quaterlist[no].arg2, "_");
        strcpy(Quaterlist[no].result,"_");
        Quaterlist[no].line=line;
        Quaterlist[no].continueflag=0;
        Quaterlist[no].breakflag=0;
        NXQ++;
    }
}
void setcontinueflag(int line)
{
    Quaterlist[line].continueflag=1;
}
void setbreakflag(int line)
{
    Quaterlist[line].breakflag=1;
}
void conti_update_Quterlist(int start,int end)
{
    for (int i=start;i<=end;i++)
    {
        if (Quaterlist[i].continueflag==1) Quaterlist[i].line=start;
        if (Quaterlist[i].breakflag==1) Quaterlist[i].line=end+1;
        Quaterlist[i].continueflag=0;
        Quaterlist[i].breakflag=0;
    }
}
