%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"
%}

%%
"*"             { return T_TIMES; }
"/"             { return T_DIVIDE; }
"+"             { return T_PLUS; }
"-"             { return T_MINUS; }
"%"             { return T_MOD; }
"++"			      { return T_DOUBLEPLUS; }
"--"			      { return T_DOUBLEMINUS; }
"<<"            { return T_LEFTSHIFT; }
">>"            { return T_RIGHTSHIFT; }
"("             { return T_LBRACKET; }
")"             { return T_RBRACKET; }
"["             { return T_LSQUARE; }
"]"             { return T_RSQUARE; }
"||"            { return T_OR; }
"&&"            { return T_AND; }
"&"             { return T_BITAND; }
"|"             { return T_BITOR; }
"^"             { return T_BITXOR; }
"~"             { return T_BITNOT; }
"{"             { return T_LCURLY; }
"}"             { return T_RCURLY; }
"!"             { return T_NOT; }
"<"             { return T_LESS; }
">"             { return T_GREAT; }
"<="			      { return T_LESSEQUAL; }
">="			      { return T_GREATEQUAL; }
"=="			      { return T_DOUBLEEQUAL; }
"!="			      { return T_NOTEQUAL; }
"="             { return T_EQUAL; }
"+="            { return T_PLUSASSIGN; }
"-="            { return T_MINUSASSIGN; }
"*="            { return T_MULTASSIGN; }
"/="            { return T_DIVASSIGN; }
"%="            { return T_MODASSIGN; }
"<<="           { return T_LEFTASSIGN; }
">>="           { return T_RIGHTASSIGN; }
"&="            { return T_ANDASSIGN; }
"^="            { return T_XORASSIGN; }
"|="            { return T_ORASSIGN; }
"->"            { return T_POINTER; }
";"             { return T_SEMI; }
":"             { return T_COLON; }
","             { return T_COMMA; }
"."             { return T_STOP; }
"..."           { return T_ELLIPSIS; }
"?"             { return T_QUESTION; }
void            { return T_VOID; }
while           { return T_WHILE; }
if              { return T_IF; }
else            { return T_ELSE; } 
int             { return T_INT; }
goto            { return T_GOTO; }
continue        { return T_CONTINUE; }
break           { return T_BREAK; }
return          { return T_RETURN; }
do              { return T_DO; }
for             { retrurn T_FOR; }
switch          { return T_SWITCH; }
case            { return T_CASE; }
default         { return T_DEFAULT; }
const           { return T_CONST; }
char            { return T_CHAR; }
short           { return T_SHORT; }
long            { return T_LONG; }
double          { return T_DOUBLE; }
signed          { return T_UNSIGNED; }
volatile        { return T_VOLATILE; }
struct          { return T_STRUCT; }
union           { return T_UNION; }
typedef         { return T_TYPEDEF; }
extern          { return T_EXTERN; }
static          { return T_STATIC; }
auto            { return T_AUTO; }
register        { return T_REGISTER; }
sizeof          { return T_SIZEOF; }


{[a-z]}({[a-z]}|{0-9})*     { return T_IDENTIFIER; }

[a-z]?\"(\\.|[^\\"])*\"     { return T_STRING_LITERAL; }


[0-9]+([.][0-9]*)? { yylval.number=strtod(yytext, 0); return T_NUMBER; }



[a-z]+          { yylval.string=new std::string(yytext); return T_VARIABLE; }

[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
