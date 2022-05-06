%code requires{
  #include "ast.hpp"
  #include <cassert>
  #include "ast_list.hpp"

  extern const Node *g_root; // A way of getting the AST out

  //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

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.

//get_assembly
%union{
  const Node *expr;
  std::vector<const Node*> *exprlist;
  //List *exprlist;
  int number;
  std::string *string;
  yytokentype token;
}

%token T_TIMES T_DIVIDE T_PLUS T_MINUS T_EXPONENT T_AND T_OR T_NOT T_DOUBLEPLUS T_DOUBLEMINUS
%token T_LBRACKET T_RBRACKET T_LCURLY T_RCURLY T_LSQUARE T_RSQUARE T_SEMI T_MOD
%token T_BITAND T_BITOR T_BITXOR T_BITNOT T_LEFTSHIFT T_RIGHTSHIFT
%token T_INT T_VOID T_DOUBLEEQUAL T_NOTEQUAL T_LESSEQUAL T_GREATEQUAL
%token T_IF T_ELSE T_WHILE T_GREAT T_LESS T_EQUAL T_PLUSASSIGN T_MINUSASSIGN T_MULTASSIGN T_DIVASSIGN T_MODASSIGN
%token T_LEFTASSIGN T_RIGHTASSIGN T_ANDASSIGN T_XORASSIGN T_ORASSIGN T_COMMA T_GOTO T_CONTINUE T_BREAK T_RETURN
%token T_DO T_FOR T_SWITCH T_COLON T_CASE T_DEFAULT T_ELLIPSIS T_CONST T_CHAR T_SHORT T_LONG
%token T_DOUBLE T_SIGNED T_UNSIGNED T_TYPENAME T_STOP T_STRING_LITERAL T_IDENTIFIER T_VOLATILE T_STRUCT
%token T_UNION T_TYPEDEF T_EXTERN T_STATIC T_AUTO T_REGISTER T_QUESTION T_SIZEOF T_POINTER
%token T_CONSTANT

%type <expr>   PRIMARY UNARY  SELECTION STATEMENT ITERATION FUNCTION_DEF EXTERNAL_DECLARATION
%type <expr>   TRANSLATION_UNIT JUMP EXPRESSION_STATEMENT COMPOUND LABELED
%type <expr>   INITIALISER DIRECT_ABSTRACT_DECLARATOR ABSTRACT_DECLARATOR TYPE_NAME 
%type <expr>   PARAMETER_DECLARATION PARAMETER_TYPE_LS TYPE_QUALIFIER_LS
%type <expr>   POINTER DIRECT_DECLARATOR DECLARATOR TYPE_QUALFIIER ENUM  ENUM_SPECIFIER STRUCT_DECLARATOR 
%type <expr>   STRUCT_OR_UNION STRUCT_OR_UNION_SPECIFIER TYPE_SPECIFIER STORAGE_CLASS INIT_DECLARATOR
%type <expr>   INIT_DECLARATOR_LS DECLARATION_SPECIFIER DECLARATION EXPRESSION ASSIGNMENT CONDITIONAL
%type <expr>   LOGICAL_OR LOGICAL_AND INCLUSIVE_OR EXCLUSIVE_OR AND_EXP EQUALITY RELATIONAL SHIFTING ADDITION MULTIPLICATION 
%type <expr>   CASTING UNARY_OPERATOR POST_EXPRESSION TRANSLATION ROOT STRUCT_DECLARATION CONSTANT
%type <exprlist>  STRUCT_DELCLARATOR_LS ARGUMENT_EXPRESSION_LS SPECIFIER_QUALIFIER_LS STRUCT_DECLARATION_LS ENUM_LS
%type <exprlist> PARAMETER_LS IDENTIFIER_LS INITIALISER_LS DECLARATION_LS STATEMENT_LS
%type <string> T_IDENTIFIER T_CONSTANT
%type <number> T_helsd


%start ROOT

%%

ROOT : TRANSLATION_UNIT { g_root = $1;}
     ;

FUNCTION_DEF : DECLARATION_SPECIFIER DECLARATOR DECLARATION_LS COMPOUND { $$ = new FunctionDefinition($1, $2, $3, $4);}
             | DECLARATION_SPECIFIER DECLARATOR COMPOUND { $$ = new FunctionDefinition($1, $2, NULL, $4);}
             | DECLARATOR DECLARATION_LS COMPOUND { $$ = new FunctionDefinition(NULL, $2, $3, $4);}
             | DECLARATOR COMPOUND { $$ = new FunctionDefinition(NULL, $2, NULL, $4);}
             ;

EXTERNAL_DECLARATION : DECLARATION {$$ = $1;}
                     | FUNCTION_DEF {$$ = $1;}
                     ;

TRANSLATION_UNIT : EXTERNAL_DECLARATION {$$ = $1;}
                 | TRANSLATION_UNIT EXTERNAL_DECLARATION { $$ = $1;}
                 ;

JUMP : T_CONTINUE T_SEMI {$$ = new Continue();}
     | T_BREAK T_SEMI {$$ = new Break();}
     | T_RETURN T_SEMI {$$ = new ReturnFunct(NULL);}
     | T_RETURN EXPRESSION T_SEMI { $$ = new ReturnFunct($2);}
     ;

ITERATION : T_WHILE T_LBRACKET EXPRESSION T_RBRACKET STATEMENT {$$ = new While($3, $5);}
          //| T_DO STATEMENT T_WHILE T_LBRACKET EXPRESSION T_RBRACKET T_SEMI
          | T_FOR T_LBRACKET EXPRESSION_STATEMENT EXPRESSION_STATEMENT T_RBRACKET STATEMENT {$$ = new For($3, $4, NULL, $6);}
          | T_FOR T_LBRACKET EXPRESSION_STATEMENT EXPRESSION_STATEMENT EXPRESSION T_RBRACKET STATEMENT {$$ = new For($3, $4, $5, $6);}

SELECTION : T_IF T_LBRACKET EXPRESSION T_RBRACKET STATEMENT {$$ = new IfStatement($3, $5);}
          | T_IF T_LBRACKET EXPRESSION T_RBRACKET STATEMENT T_ELSE STATEMENT {$$ = new IfElse($3, $5, $7);}
          | T_SWITCH T_LBRACKET EXPRESSION T_RBRACKET STATEMENT {$$ = new Switch($3, $5);}
          ;

EXPRESSION_STATEMENT : T_SEMI {$$ = new ExpressionStatement(NULL);}
                     | EXPRESSION T_SEMI { $$ = new ExpressionStatement($1);}
                     ;

STATEMENT_LS : STATEMENT {$$ = StatementList(NULL, $1); }
             | STATEMENT_LS STATEMENT { $$ = StatementList($1, $2);}
             ;

DECLARATION_LS : DECLARATION { $$ = DeclList(NULL, $1);}
               | DECLARATION_LS DECLARATION { $$ = DeclList($1, $2);}
               ;

COMPOUND : T_LCURLY T_RCURLY { $$ = new Compound(NULL, NULL);}
         | T_LCURLY STATEMENT_LS T_RCURLY { $$ = new Compound(NULL, $2);}
         | T_LCURLY DECLARATION_LS T_RCURLY { $$ = new Compound ($2, NULL);}
         | T_LCURLY DECLARATION_LS STATEMENT_LS T_RCURLY {$$ = new Compound ($2, $3);}
         ;

LABELED : //T_IDENTIFIER T_COLON STATEMENT
        | T_CASE CONSTANT T_COLON STATEMENT {$$ = new Case($2, $4);}
        | T_DEFAULT T_COLON STATEMENT {$$ = new Default($3);}
        ;

STATEMENT : LABELED {$$ = $1;}
          | COMPOUND {$$ = $1;}
          | EXPRESSION_STATEMENT {$$ = $1;}
          | SELECTION {$$ = $1;}
          | ITERATION {$$ = $1;}
          | JUMP {$$ = new JumpStatement($1);}
          ;

INITIALISER_LS : INITIALISER {$$ = InitialiserList(NULL, $1); }
               | INITIALISER_LS T_COMMA INITIALISER {$$ = new InitialiserList($1, $3);}        
               ;

INITIALISER : ASSIGNMENT {$$ = $1;}
            //| T_LCURLY INITIALISER_LS T_RCURLY //{$$ = Initialisation_Array_Declarator($2);}
            ;
/*
DIRECT_ABSTRACT_DECLARATOR : T_LBRACKET ABSTRACT_DECLARATOR T_RBRACKET
                           | T_LSQUARE T_RSQUARE
                           | T_LSQUARE CONSTANT T_RSQUARE
                           | DIRECT_ABSTRACT_DECLARATOR T_LSQUARE T_RSQUARE
                           | DIRECT_ABSTRACT_DECLARATOR T_LSQUARE CONSTANT T_RSQUARE
                           | T_LBRACKET T_RBRACKET
                           | T_LBRACKET PARAMETER_LS T_RBRACKET
                           | DIRECT_ABSTRACT_DECLARATOR T_LBRACKET T_RBRACKET
                           | DIRECT_ABSTRACT_DECLARATOR T_LBRACKET PARAMETER_LS T_RBRACKET
                           ;

ABSTRACT_DECLARATOR : POINTER
                    | DIRECT_ABSTRACT_DECLARATOR
                    | POINTER DIRECT_ABSTRACT_DECLARATOR
                    ;

TYPE_NAME : SPECIFIER_QUALIFIER_LS
          | SPECIFIER_QUALIFIER_LS ABSTRACT_DECLARATOR
          ;
*/
IDENTIFIER_LS : T_IDENTIFIER {$$ = new IdentifierList(NULL, $1);}
              | IDENTIFIER_LS T_COMMA T_IDENTIFIER {$$ = new IdentifierList($1, $2);}
              ;
/*
PARAMETER_DECLARATION : DECLARATION_SPECIFIER DECLARATOR {$$ = new VectorDeclaration();}
                      | DECLARATION_SPECIFIER {$$ = $1;}
                      | DECLARATION_SPECIFIER ABSTRACT_DECLARATOR
                      ;

PARAMETER_LS : PARAMETER_DECLARATION { $$ = ParameterList(NULL, $1); }
             | PARAMETER_LS T_COMMA PARAMETER_DECLARATION { $$ = ParameterList($1, $3);}
             ;

TYPE_QUALIFIER_LS : TYPE_QUALFIIER {$$ = new_list($1);}
                  | TYPE_QUALIFIER_LS TYPE_QUALFIIER {$$ = add_list($1, $2);}
                  ;
*/
POINTER : T_TIMES {$$ = new typedef("POINTER", *$1); delete $1;}
        //| T_TIMES POINTER {$$ = }
        //| T_TIMES TYPE_QUALIFIER_LS
        //| T_TIMES TYPE_QUALIFIER_LS POINTER
        ;

DIRECT_DECLARATOR : T_IDENTIFIER { $$ = new Direct($1);}
                  //| T_LBRACKET DECLARATOR T_RBRACKET
                  //| DIRECT_DECLARATOR T_LSQUARE CONSTANT T_RSQUARE //{ $$ = new Direct($1, $2);}
                  | DIRECT_DECLARATOR T_LSQUARE T_RSQUARE { $$ = new Direct($1);}
                  | DIRECT_DECLARATOR T_LBRACKET T_RBRACKET 
                  //| DIRECT_DECLARATOR T_LBRACKET PARAMETER_LS T_RBRACKET
                  //| DIRECT_DECLARATOR T_LBRACKET IDENTIFIER_LS T_RBRACKET {}
                  ;

DECLARATOR : // POINTER DIRECT_DECLARATOR {$$}
           | DIRECT_DECLARATOR { $$ = new Declarator($1);}
           ;

//TYPE_QUALFIIER : T_CONST
//               | T_VOLATILE
//               ;

ENUM : T_IDENTIFIER {$$ = new Declaration($1);}
     //| T_IDENTIFIER T_EQUAL CONSTANT {}
     ;

/*ENUM_LS : ENUM 
        | ENUM_LS T_COMMA ENUM 
        ;          

ENUM_SPECIFIER : ENUM T_LCURLY ENUM_LS T_RCURLY
               | ENUM T_IDENTIFIER T_LCURLY ENUM_LS T_RCURLY
               | ENUM T_IDENTIFIER
               ;

STRUCT_DECLARATOR : DECLARATOR {$$ = $1;}
                  | T_COLON CONSTANT
                  | DECLARATOR T_COLON CONSTANT
                  ;       

STRUCT_DELCLARATOR_LS : STRUCT_DECLARATOR {$$ = new_list($1);}
                      | STRUCT_DECLARATION_LS T_COMMA STRUCT_DECLARATOR {$$ = add_list($1, $3);}
                      ;

SPECIFIER_QUALIFIER_LS : TYPE_SPECIFIER SPECIFIER_QUALIFIER_LS
                       | TYPE_SPECIFIER
                       | TYPE_QUALFIIER SPECIFIER_QUALIFIER_LS
                       | TYPE_QUALFIIER 
                       ;

STRUCT_DECLARATION : SPECIFIER_QUALIFIER_LS STRUCT_DELCLARATOR_LS T_SEMI
                   ;

STRUCT_DECLARATION_LS : STRUCT_DECLARATION {$$ = new_list($1);}
                      | STRUCT_DECLARATION_LS STRUCT_DECLARATION {$$ = add_list($1, $2);}
                      ;

STRUCT_OR_UNION : T_STRUCT
                | T_UNION
                ;

STRUCT_OR_UNION_SPECIFIER : STRUCT_OR_UNION T_IDENTIFIER T_LCURLY STRUCT_DECLARATION_LS T_RCURLY
                          | STRUCT_OR_UNION T_LCURLY STRUCT_DECLARATION_LS T_RCURLY
                          | STRUCT_OR_UNION T_IDENTIFIER
                          ;
*/
TYPE_SPECIFIER : T_INT { $$ = new Integer($1);}
               //| T_CHAR {$$ = new }
               //| T_SHORT {$$ = new }
               | T_VOID {$$ = new Void($1);}
               //| T_LONG {$$ = new }
               | T_DOUBLE {$$ = new Double($1);}
               //| T_SIGNED {$$ = new ()}
               | T_UNSIGNED {$$ = new Unsigned($1);}
               //| T_TYPENAME {$$ = new }
               //| STRUCT_OR_UNION_SPECIFIER
               //| ENUM_SPECIFIER
               ;

//STORAGE_CLASS : 
                //_TYPEDEF {$$}
              //| T_EXTERN
              //| T_STATIC
              //| T_AUTO
              //| T_REGISTER
              ;

INIT_DECLARATOR : DECLARATOR {$$ = new Initialisation_Variable_Declarator($1, NULL);}
                | DECLARATOR T_EQUAL INITIALISER {$$ = new Initialisation_Variable_Declarator($1, $3);}
                ;
/*
INIT_DECLARATOR_LS : INIT_DECLARATOR
                   | INIT_DECLARATOR_LS T_COMMA INIT_DECLARATOR
                   ;
*/
DECLARATION_SPECIFIER : //STORAGE_CLASS {$$ = $1;}
                      //| STORAGE_CLASS DECLARATION_SPECIFIER
                      | TYPE_SPECIFIER {$$ = $1;}
                      //| TYPE_SPECIFIER DECLARATION_SPECIFIER 
                      //| TYPE_QUALFIIER {$$ = $1;}
                      //| TYPE_QUALFIIER DECLARATION_SPECIFIER
                      ;

DECLARATION : DECLARATION_SPECIFIER T_SEMI {$$ = new Declaration(*$1);}
            //| DECLARATION_SPECIFIER INIT_DECLARATOR_LS T_SEMI {$$ = new Declaration()}
            ;
          
CONSTANT : CONDITIONAL {$$ = $1;}
	       ;


EXPRESSION : ASSIGNMENT {$$ = $1;}
	         ;

ASSIGNMENT : CONDITIONAL {$$ = $1;}
          // | UNARY T_EQUAL ASSIGNMENT //{ $$ = new EqualAssign($1, $3);  std::cout << "assign expression" << std::endl;}
           | UNARY T_PLUSASSIGN ASSIGNMENT  { $$ = new AddAssign($1, $3);}
           | UNARY T_MINUSASSIGN ASSIGNMENT { $$ = new SubAssign($1, $3);}
       // | UNARY T_MULTASSIGN ASSIGNMENT //{ $$ = new MultAssign($1, $3);}
         //  | UNARY T_DIVASSIGN ASSIGNMENT //{ $$ = new DivAssign($1, $3);}
         //  | UNARY T_MODASSIGN ASSIGNMENT //{ $$ = new ModAssign($1, $3);}
          // | UNARY T_LEFTASSIGN ASSIGNMENT //{ $$ = new LeftAssign($1, $3);}
         //  | UNARY T_RIGHTASSIGN ASSIGNMENT //{ $$ = new RightAssign($1, $3);}
          // | UNARY T_ANDASSIGN ASSIGNMENT //{ $$ = new AndAssign($1, $3);}
          // | UNARY T_XORASSIGN ASSIGNMENT //{ $$ = new XorAssign($1, $3);}
          // | UNARY T_ORASSIGN ASSIGNMENT //{ $$ = new OrAssign($1, $3);}
           ;

CONDITIONAL : LOGICAL_OR {$$ = $1;}
            //| LOGICAL_OR T_QUESTION EXPRESSION T_COLON CONDITIONAL
            ;

LOGICAL_OR : LOGICAL_AND {$$ = $1;}
	         | LOGICAL_AND T_OR LOGICAL_AND {$$ = new LogOrOperator($1, $3);}
	         ;

LOGICAL_AND : INCLUSIVE_OR {$$ = $1;}
	        | LOGICAL_AND T_AND INCLUSIVE_OR {$$ = new LogAndOperator($1, $3);}
	        ;

INCLUSIVE_OR : EXCLUSIVE_OR {$$ = $1;}
	           | INCLUSIVE_OR T_BITOR EXCLUSIVE_OR {$$ = new BitOrOperator($1, $3);}
	           ;

EXCLUSIVE_OR : AND_EXP {$$ = $1;}
	           | EXCLUSIVE_OR T_BITXOR AND_EXP {$$ = new BitXorOperator($1, $3);}
	           ;

AND_EXP : EQUALITY {$$ = $1;}
        | AND_EXP T_BITAND EQUALITY {$$ = new BitAndOperator($1, $3);}
	;

EQUALITY : RELATIONAL {$$ = $1;}
	 | EQUALITY T_DOUBLEEQUAL RELATIONAL {$$ = new DoubleEqual($1, $3);}
	 | EQUALITY T_NOTEQUAL RELATIONAL {$$ = new NotEqual($1, $3);}
         ;

RELATIONAL : SHIFTING {$$ = $1;}
	         | RELATIONAL T_LESS SHIFTING {$$ = new LessThanOperator($1, $3);}
	         | RELATIONAL T_GREAT SHIFTING {$$ = new GreaterThanOperator($1, $3);}
	         | RELATIONAL T_LESSEQUAL SHIFTING {$$ = new LessThanEqOperator ($1, $3);}
	         | RELATIONAL T_GREATEQUAL SHIFTING {$$ = new GreaterThanEqOperator($1, $3);}
	         ;

SHIFTING : ADDITION {$$ = $1; std::cout << "add" << std::endl;}
         | SHIFTING T_LEFTSHIFT ADDITION {$$ = new LeftBitShift($1, $3);}
	 | SHIFTING T_RIGHTSHIFT ADDITION {$$ = new RightBitShift($1, $3);}
         ;

ADDITION : MULTIPLICATION {$$ = $1; std::cout << "mult" << std::endl;}
	       | ADDITION T_PLUS MULTIPLICATION {$$ = new AddOperator($1, $3);}
	       | ADDITION T_MINUS MULTIPLICATION {$$ = new SubOperator($1, $3);}
	       ;

MULTIPLICATION : CASTING {$$ = $1; std::cout << "cast" << std::endl;}
	             | MULTIPLICATION T_TIMES CASTING {$$ = new MultOperator($1, $3);}
	             | MULTIPLICATION T_DIVIDE CASTING {$$ = new DivOperator($1, $3);}
	             //| MULTIPLICATION T_MOD CASTING {$$ = new ModOperator($1, $3);}
	             ;

CASTING : UNARY {$$ = new Casting($1);}
        //| T_LBRACKET TYPE_NAME T_RBRACKET CASTING
        ;

/*UNARY_OPERATOR : T_BITAND {}
               | T_BITNOT 
               | T_MINUS 
               | T_PLUS 
               | T_TIMES 
               ;
*/
UNARY : POST_EXPRESSION { $$ = $1;}//std::cout << "post" << std::endl;}
      | T_DOUBLEPLUS UNARY {$$ = new Increment($2);}
      | T_DOUBLEMINUS UNARY {$$ = new Decrement_Expression{$2};}
      //| UNARY_OPERATOR CASTING
      | T_SIZEOF UNARY_OPERATOR {$$ = new SizeofTypeExpression($2);}
      //| T_SIZEOF T_LBRACKET TYPE_NAME T_RBRACKET {$$ = new SizeofVariableExpression($3);}
      ;

//ARGUMENT_EXPRESSION_LS : ASSIGNMENT 
                       //| ARGUMENT_EXPRESSION_LS T_COMMA ASSIGNMENT 
                      // ;

POST_EXPRESSION : PRIMARY {$$ = $1;}
           | POST_EXPRESSION T_LBRACKET T_RBRACKET {$$ = new FunctionDefinition(NULL, $1, NULL, NULL);} // function without arguments
           //| POST_EXPRESSION T_DOUBLEPLUS 
           //| POST_EXPRESSION T_DOUBLEMINUS {$$ = new Post_Decrement{$1};}
           //| POST_EXPRESSION T_POINTER T_IDENTIFIER //
           //| POST_EXPRESSION T_LSQUARE EXPRESSION T_RSQUARE
           //| POST_EXPRESSION T_LBRACKET ARGUMENT_EXPRESSION_LS T_RBRACKET
           //| POST_EXPRESSION T_STOP T_IDENTIFIER
           ;

PRIMARY :  T_IDENTIFIER {$$ = Identifier($1);}
       //| T_LBRACKET EXPRESSION T_RBRACKET 
       //| T_STRING_LITERAL
       | T_CONSTANT {$$ = new Integer($1);}
       ;

%%

const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}