#include "ast.hpp"
#include "context.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	// Parse the AST
	const Expression *ast = parseAST();
	// std::ofstream output(argv[4]);
	//  evaluate it with the bindings given
	Context context;
	ast->mips(std::cout, context);
}
