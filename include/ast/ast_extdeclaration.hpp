#ifndef ast_extdeclaration_hpp
#define ast_extdeclaration_hpp

#include <string>
#include <ostream>
#include "context.hpp"
#include "ast_node.hpp"
using namespace std;

class Statement : public Node
{
};

class Program : public Node
{
private:
	Node_Ptr left;
	Node_Ptr right;

public:
	Program(Node_Ptr _left, Node_Ptr _right) : left(_left), right(_right) {}

	virtual void compile(std::ostream &dst, Context &context) const override
	{
		left->compile(dst, context);
		right->compile(dst, context);
	}
};

class DeclarationExt : public Node
{
};

class Direct : public DeclarationExt
{

	virtual string get_VariableName()
	{
		return " ";
	}

	virtual int get_VariableSize()
	{
		return 0;
	}

	virtual void compile_declaration(ostream &dst, Context &context, typedefine decltype, bool pointer) const {}
	virtual void compile_declaration_initialisdation(ostream &dst, Context &context, typedefine decltype, Expression *expression, bool pointer) const {}
	virtual void compile_declaration_array_initialisation(ostream &dst, Context &context typedefine decltype, vector<Expression *> *expression_vector) const {}
};

class Declaration : public DeclarationExt
{
private:
	typedefine TYPE;
	bool pointer;
	vector<Declarator *> *DeclList;

public:
	Declaration(typedefine _TYPE, vector<Direct *> *_DeclList = NULL)
		: TYPE(_TYPE), pointer(_TYPE.get_pointer_capability()), DeclList(_DeclList) {}

	virtual string getParam()
	{
		return (*DeclList)[0]->get_variable_name();
	}

	type get_type()
	{
		return TYPE.get_variable_type();
	}

	bool get_pointer()
	{
		return pointer;
	}

	virtual void compile(ostream &dst, Context &context) const override
	{
		if (DeclList != NULL)
		{
			for (int i = 0; i < DeclList->size(); i++)
			{
				Direct *temp_declarator = DeclList->at(i);
				(*temp_declarator).compile_declaration(dst, context, TYPE, pointer);
			}
		}
	}
};

class FunctionDefinition : public DeclarationExt
{
private:
	typedefine *TYPE;
	string ID;
	vector<Declaration *> *parameter_list;
	Statement *statements;

public:
	FunctionDefinition(typedefine *_TYPE, string _ID, vector<Declaration *> *_parameter_list, Statement *_statements)
		: TYPE(_TYPE), ID(_ID), parameter_list(_parameter_list), statements(_statements) {}

	virtual void compile(ostream &dst, Context &context) const override
	{

		context.expand_context_scope();
		context.set_LOCAL();
		context.set_main_return_label("RETURN");

		dst << endl;
		dst << "Opening directive" << endl;
		dst << endl;

		dst << "\t"
			<< ".text" << endl;
		dst << "\t"
			<< ".global"
			<< "\t" << ID << endl;
		dst << "\t"
			<< ".ent"
			<< "\t" << ID << endl;
		dst << "\t"
			<< ".type"
			<< "\t" << ID << ", @function" << endl;

		dst << endl;
		dst << "call funciton" << endl;
		dst << endl;

		dst << ID << ":" << endl;

		dst << endl;
		dst << "allocate stack" << endl;
		dst << endl;

		dst << "\t"
			<< "sw"
			<< "\t"
			<< "\t"
			<< "$31,"
			<< "-4"
			<< "($29)" << endl;
		dst << "\t"
			<< "sw"
			<< "\t"
			<< "\t"
			<< "$30,"
			<< "-8"
			<< "($29)" << endl;
		dst << "\t"
			<< "addiu"
			<< "\t"
			<< "$29,$29,"
			<< "-8" << endl;
		dst << "\t"
			<< "move"
			<< "\t"
			<< "$30,$29" << endl;
		dst << endl;
		dst << "program assemly" << endl;
		dst << endl;

		if (parameter_list != NULL)
		{
			int argument_stack_pointer = 4;

			string argument_integer_registers[4] = {"$4", "$5", "$6", "$7"};
			string argument_float_registers[4] = {"$f12", "$f14"};
			string argument_double_registers[4] = {"$f12", "$f13", "$f14", "$f15"};

			for (int i = 0; i < parameter_list->size(); i++)
			{
				argument_stack_pointer += 4;
				type argument_type = (*parameter_list)[i]->get_type();

				if ((argument_type == FLOAT) && (i < 2))
				{
					context.store_float_register(dst, argument_float_registers[i], argument_stack_pointer);
				}
				else if ((argument_type == DOUBLE) && (i < 2))
				{

					int regind = 2 * (i + 1);

					argument_stack_pointer += 4;
					context.store_float_register(dst, argument_double_registers[regind - 2], argument_stack_pointer);

					argument_stack_pointer -= 4;
					context.store_float_register(dst, argument_double_registers[regind - 1], argument_stack_pointer);

					argument_stack_pointer += 4;
				}
				else if (((argument_type == FLOAT) && (i < 4)) || ((argument_type == INT || argument_type == UNSIGNED_INT) && (i < 4)))
				{
					if (argument_type == FLOAT)
					{
						context.output_store_operation(dst, argument_type, argument_integer_registers[i], "$30", argument_stack_pointer);
					}
					else
					{
						context.output_store_operation(dst, argument_type, argument_integer_registers[i], "$30", argument_stack_pointer);
					}
				}
				context.make_new_argument((*parameter_list)[i]->getParam(), (*parameter_list)[i]->get_type(), NORMAL, argument_stack_pointer, (*parameter_list)[i]->get_pointer());
			}
		}

		if (statements != NULL)
		{
			statements->mips(dst, context);
		}

		if (ID == "main")
		{
			dst << "\t"
				<< "move"
				<< "\t"
				<< "$2, $0" << endl;
		}

		dst << endl;
		dst << context.get_function_return_label() << ":" << endl;

		dst << endl;
		dst << "deallocate stack" << endl;
		dst << endl;

		dst << "\t"
			<< "move"
			<< "\t"
			<< "$29, $30" << endl;
		dst << "\t"
			<< "addiu"
			<< "\t"
			<< "$29, $29,"
			<< "8" << endl;
		dst << "\t"
			<< "lw"
			<< "\t"
			<< "\t"
			<< "$30,"
			<< "-8"
			<< "($29)" << endl;
		dst << "\t"
			<< "lw"
			<< "\t"
			<< "\t"
			<< "$31,"
			<< "-4"
			<< "($29)" << endl;
		dst << "\t"
			<< "j"
			<< "\t"
			<< "\t"
			<< "$31" << endl;

		dst << endl;
		dst << "closiing directive" << endl;
		dst << endl;
		dst << "\t"
			<< ".end"
			<< "\t" << ID << endl;

		context.deallocate_stack();
		context.shrink_context_scope();
		context.set_GLOBAL();
	}
};

#endif