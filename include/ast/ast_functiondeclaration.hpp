#ifndef ast_functiondeclaration_hpp
#define ast_functiondeclaration_hpp

#include <string>
#include <ostream>
#include "context.hpp"
#include "ast_node.hpp"
using namespace std;

class Program : public Expression
{

private:
    Expression_Ptr left;
    Expression_Ptr right;

public:
    Program(Expression_Ptr _left, Expression_Ptr _right)
        : left(_left), right(_right) {}

    virtual void compile(ostream &dst, Context &context) const override
    {
        left->mips(dst, context)
            right->mips(dst, context)
    }
};

class Variable_Declareator : public Declarator
{

private:
    string Variable_Name;
    bool pointer;

public:
    Variable_Declare(string _Variable_Name, bool pointer)
        : Variable_Name(_Variable_Name), pointer(_pointer) {}

    virtual string get_Variable_Name()
    {
        return Variable_Name;
    }

    virtual int get_Variable_Size()
    {
        return 4;
    }

    virtual void compile_declaration(ostream &dst, Context &context, typedefine decltype, bool pointer) const override
    {
        type Variable_Type;
        int Frame_Pointer1;

        if (pointer)
        {
            variable compile_variable = context.new_variable(Variable_Name, decltype, )
        }
    }
};

class Array_Declarator : public Declarator
{

private:
    string Variable_Name;
    int ArraySize;
    Expression *expression;

public:
    Array_Declarator(string _Variable_Name, Expression *_ArraySize)
    {
        Variable_Name = _Variable_Name;
        if (_ArraySize != NULL)
        {
            ArraySize = _ArraySize->evaluate();
        }
        else
        {
            ArraySize = -1;
        }
    }

    virtual string get_Variable_Name()
    {
        return Variable_Name;
    }

    virtual string get_Variable_Size()
    {
        return ArraySize;
    }

    virtual void compile(ostream &dst, Context &context) const override
    {

        var array_var = context.get_variable(Variable_Name);
        int Array_Frame_Pointer = 0;

        if (context.get_context_scope() == LOCAL)
        {
            dst << "\t"
                << "Local array" << endl;
            for (int i = 0; i < ArraySize; i++)
            {
                Array_Frame_Pointer = 4 * (i) + ArraySize
                                                    context.output_store_operation(dst, array_var.get_variable_type(), "$0", "$30", array_frame_pointer);
            }
        }

        else
        {
            dst << "\t"
                << "Global Array" << endl;
            dst << "\t"
                << ".global"
                << "\t" << Variable_Name << endl;
            dst << "\t"
                << ".data" << endl;
            dst << Variable_Name << ":" << endl;
            for (int i = 0; i < array_size; i++)
            {
                dst << "\t"
                    << ".space " << array_size * 4 << endl;
            }
        }
    }
    virtual void compile_declaration(ostream &dst, Context &context, typedefine decltype, bool pointer) const override
    {
        decltype.increment_array_tracker();
        var array_var = context.new_variable(Variable_Name, decltype, ARRAY, 0, ArraySize);
        int array_frame_pointer = 0;

        if (context.get_context_scope() == LOCAL)
        {
            dst << "\t"
                << "store in local array" << endl;
            for (int i = 0; i < array_size; i++)
            {
                array_frame_pointer = 4 * (i) + array_var.get_variable_address();
                context.output_store_operation(dst, decltype.get_variable_type(), "$0", "$30", array_frame_pointer);
            }
        }
        else
        {
            dst << "\t"
                << "store in global aray" << endl;
            dst << "\t" << Variable_Name << " " << array_size * 4 << endl;
        }
    }

    virtual void compile_declaration_array_initialisation(ostream &dst, Context &context, typedefine decltype, vector<Expression *> *expression_vector) const
    {
        int init_vector_size = expression_vector->size();
        variable array_var = context.new_variable(Variable_Name, decltype, ARRAY, init_vector_size);

        for (int i = 0; i < array_size; i++)
        {
            if (i < init_vector_size)
            {
                int array_offset = 4 * (i) + array_var.get_variable_address();
                context.allocate_stack();
                int stack_pointer = context.get_stack_pointer();
                string init_register = "$8";

                (*expression_vector)[i]->mips(dst, context);

                context.deallocate_stack();
                context.load_register(dst, init_register, stack_pointer);
                context.output_store_operation(dst, decltype.get_variable_type(), init_register, "$30", array_offset);
            }
            else
            {
                int array_offset = 4 * (i) + array_var.get_variable_address();
                context.output_store_operation(dst, declarator_type.get_variable_type(), "$0", "$30", array_offset);
            }
        }
    }
};

class Initialisation_Variable_Declarator : public Declarator
{
private:
    Declarator *init_declarator;
    Expression *init_expressions;

public:
    Initialisation_Variable_Declarator(Declarator *_init_declarator, Expression *_init_expressions)
        : init_declarator(_init_declarator), init_expressions(_init_expressions) {}

    virtual void compile_declaration(ostream &dst, Context &context, typedefine decltype, bool pointer) const override
    {
        init_declarator->mips_declaration_initialisation(dst, context, decltype, init_expressions, pointer);
    }
};

class Initialisation_Array_Declarator : public Declarator
{

private:
    Declarator *init_declarator;
    vector<Expression *> *init_vector;

public:
    Initialisation_Array_Declarator(Declarator *_init_declarator, vector<Expression *> *_init_vector)
        : init_declarator(_init_declarator), init_vector(_init_vector) {}

    virtual void compile(ostream &dst, Context &context) const override
    {
        string initialisation_variable_name = init_declarator->get_variable_name();
        int initialisation_array_size = init_declarator->get_variable_size();
        variable array_var = context.get_variable(initialisation_variable_name);
        for (int i = 0; i < initialisation_array_size; i++)
        {
            int array_offset = 4 * i + array_var.get_variable_address();
            context.allocate_stack();
            int stack_pointer = context.get_stack_pointer();
            string init_register = "$8";
            (*init_vector)[i]->mips(dst, context);

            context.deallocate_stack();
            context.load_register(dst, init_register, stack_pointer);
            context.output_store_operation(dst, array_var.get_variable_type(), init_register, "$30", array_offset);
        }
    }
    virtual void compile_declaration(ostream &dst, Context &context, typedef decltype, bool pointer) const override
    {
        init_declarator->mips_declaration_array_initialisation(dst, context, decltype, init_vector);
    }
};

class Function_Prototype_Declaration : public Declarator
{

private:
    string FunctionName;
    vector<Declaration *> *parameter_list;

public:
    Function_Prototype_Declaration(string _FunctionName, vector<Declaration *> *_parameter_list)
        : FunctionName(_FunctionName), parameter_list(_parameter_list) {}

    virtual void compile_declaration(ostream &dst, Context &context, typedefine decltype, bool pointer) const override
    {
        context.new_variable(FunctionName, decltype, FUNCTION);
    }
};

class Initialisation_Enum_Declarator : public Declarator
{
private:
    Declarator *init_declarator;
    Expression *init_expressions = NULL;

public:
    Initialisation_Enum_Declarator(Declarator *_init_declarator, Expression *_init_expressions)
        : init_declarator(_init_declarator), init_expressions(_init_expressions) {}

    Initialisation_Enum_Declarator(Declarator *_init_declarator)
        : init_declarator(_init_declarator) {}

    virtual void compile_declaration(ostream &dst, Context &context, typedefine decltype, bool pointer) const override
    {
        init_declarator->mips_declaration_initialisation(dst, context, decltype, init_expressions, false);
    }
};

#endif
