#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_expression.hpp"
#include "ast/ast_extdeclaration.hpp"
#include "ast/ast_functiondeclaration.hpp"
#include "ast/ast_node.hpp"
#include "ast/ast_operators.hpp"
#include "ast/ast_primatives.hpp"
#include "ast/ast_statement.hpp"
#include "ast/ast_unary.hpp"
#include "context.hpp"

extern const Expression *parseAST();

#endif
