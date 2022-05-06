#ifndef ast_unart_hpp
#define ast_unary_hpp

#include <ostream>
#include <string>
#include "context.hpp"
#include "ast_node.hpp"
using namespace std;

class Unary : public Expression
{

protected:
    Expression *expression;

public:
    Unary(Expression_Ptr _expression)
        : expression(_expression) {}

    virtual void compile(ostream &dst, Context &context) const override { dst << "unary" << endl; }
};

class Casting : public Unary
{

private:
    type CastingType;

public:
    Casting(type _CastingType, Expression_Ptr _expression)
        : CastingType(_CastingType.get_vartype()), Unary(_expression) {}

    virtual void compile(ostream &dst, Context &context) const override
    {
        string CastRegister = "$2";
        int CastAddress = context.get_stack_pointer();

        expression->mips(dst, context);

        context.store_register(dst, CastRegister, CastAddress);
    }

    virtual type get_data_type(Context &context) const override
    {
        return CastingType;
    };
};

class NegExpression : public Unary
{
private:
public:
    NegExpression(Expression_Ptr _expression)
        : Unary(_expression) {}

    virtual void compile(std::ostream &dst, Context &context) const override
    {
        string DestinationRegister = "$2";
        int stack_pointer = context.get_stack_pointer();

        expression->mips(dst, context);

        context.load_register(dst, DestinationRegister, stack_pointer);

        if (expression->get_data_type(context) == INT)
        {
            dst << "\t"
                << "sub"
                << "\t"
                << "\t" << DestinationRegister << ","
                << "$0"
                << "," << DestinationRegister << endl;
        }
        else if (expression->get_data_type(context) == FLOAT)
        {
            context.shift_to_float_reg(dst, DestinationRegister, "$f0");
            context.shift_to_float_reg(dst, "$0", "$f2");

            dst << "\t"
                << "sub.s"
                << "\t"
                << "$f0"
                << ","
                << "$f2"
                << ","
                << "$f0" << endl;

            context.shift_from_float_reg(dst, DestinationRegister, "$f0");
        }

        context.store_register(dst, DestinationRegister, stack_pointer);
    }
};

class Increment_Expression : public Unary
{

private:
    Expression_Ptr IncrementExpression;

public:
    Increment_Expression(Expression_Ptr _expression, Expression_Ptr _IncrementExpression)
        : Unary(_expression), IncrementExpression(_IncrementExpression) {}

    virtual void compile(ostream &dst, Context &context) const override
    {
        expression->mips(dst, context);
        context.allocate_stack();
        increment_expression->mips(dst, context);
        context.deallocate_stack();
    }

    virtual type get_data_type(Context &context) const override
    {
        return increment_expression->get_data_type(context);
    };
};

class Decrement_Expression : public Unary
{
private:
    Expression_Ptr DecrementExpression;

public:
    Decrement_Expression(Expression_Ptr _expression, Expression_Ptr _Decrement_Expression)
        : Unary(_expression), DecrementExpression(_DecrementExpression) {}

    virtual void compile(std::ostream &dst, Context &context) const override
    {
        expression->mips(dst, context);
        context.allocate_stack();
        decrement_expression->mips(dst, context);
        context.deallocate_stack();
    }

    virtual type get_data_type(Context &context) const override
    {
        decrement_expression->get_data_type(context);
    };
};

class Function_CallExpression : public Unary
{

private:
    vector<Expression_Ptr> *argument_list;

public:
    Function_CallExpression(Expression_Ptr _expression, vector<Expression_Ptr> *_argument_list = NULL)
        : Unary(_expression), argument_list(_argument_list) {}

    virtual void compile(ostream &dst, Context &context) const override
    {

        string variable_ID = expression->get_variable_name();
        int argument_size;
        int function_register_address = context.get_stack_pointer();
        string function_register = "$2";

        if (context.check_function_declared(variable_ID))
        {
            continue;
        }
        else
        {
            context.set_GLOBAL();
            context.new_variable(variable_ID, INT, FUNCTION);
            context.set_LOCAL();
        }

        if (argument_list != NULL)
        {
            argument_size = argument_list->size();
            for (int i = 0; i < argument_size; i++)
            {
                context.allocate_stack();
            }
            int function_stack_pointer = context.get_stack_pointer();
            string argument_registers[4] = {"$4", "$5", "$6", "$7"};

            int argument_stack_pointer = 0;
            for (int i = 0; i < argument_size; i++)
            {
                argument_stack_pointer += 4;

                // Temprorary registers
                context.allocate_stack();
                std::string temp_register = "$8";
                int temp_register_address = context.get_stack_pointer();

                (*argument_list)[i]->mips(dst, context);

                context.deallocate_stack();

                context.load_register(dst, temp_register, temp_register_address);
                dst << "\t"
                    << "sw"
                    << "\t"
                    << "\t" << temp_register << "," << function_stack_pointer + argument_stack_pointer << "($30)" << endl;
            }

            int argument_load_pointer = 0;
            int temp_register = 0;
            for (int i = 0; i < argument_size; i++)
            {
                argument_load_pointer += 4;

                if (i < 4)
                {
                    dst << "\t"
                        << "lw"
                        << "\t"
                        << "\t" << argument_registers[i] << "," << function_stack_pointer + argument_load_pointer << "($30)" << endl;
                }
                else
                {
                    temp_register = 4 + i;
                    string temp_register_string = "$" + to_string(temp_register);
                    dst << "\t"
                        << "sw"
                        << "\t"
                        << "\t" << temp_register_string << "," << function_stack_pointer + argument_load_pointer - 4 << "($30)" << endl;
                }
            }
        }
        dst << "\t"
            << "addiu"
            << "\t"
            << "$29, $29," << context.get_stack_pointer() << endl;
        dst << "\t"
            << "la"
            << "\t"
            << "\t"
            << "$2," << variable_ID << endl;
        dst << "\t"
            << "jalr"
            << "\t"
            << "$2" << endl;
        dst << "\t"
            << "addiu"
            << "\t"
            << "$29, $29," << -context.get_stack_pointer() << endl;

        for (int i = 0; i < argument_size; i++)
        {
            context.deallocate_stack();
        }

        context.store_register(dst, function_register, function_register_address);
    }
    virtual type get_data_type(Context &context) const override
    {
        string variable_ID = expression->get_variable_name();
        if (context.check_function_declared(variable_ID))
        {
            return (context.get_variable(variable_ID)).get_variable_type();
        }
        else
        {
            return type(INT);
        }
    }
};

class Array_AccExpression : public Unary
{

private:
    Expression_Ptr array_expression;

public:
    Array_AccExpression(Expression_Ptr _expression, Expression_Ptr _array_expression)
        : Unary(_expression), array_expression(_array_expression) {}

    virtual void load_variable_address(ostream &dst, Context &context) const
    {

        int array_frame_pointer = context.get_stack_pointer();
        string array_register = "$2";
        expression->mips(dst, context);

        context.allocate_stack();
        int temp_array_stack_pointer = context.get_stack_pointer();
        string temp_array_register = "$8";

        array_expression->mips(dst, context);

        context.deallocate_stack();

        context.load_register(dst, array_register, array_frame_pointer);
        context.load_register(dst, temp_array_register, temp_array_stack_pointer);

        dst << "\t"
            << "sll"
            << "\t"
            << "\t" << temp_array_register << "," << temp_array_register << "," << 2 << endl;
        dst << "\t"
            << "addu"
            << "\t" << array_register << "," << array_register << "," << temp_array_register << endl;

        context.store_register(dst, array_register, array_frame_pointer);
    };

    virtual void compile(ostream &dst, Context &context) const override
    {
        type array_type = INT;
        int array_frame_pointer = context.get_stack_pointer();
        string array_register = "$2";

        load_variable_address(dst, context);

        dst << "\t"
            << "Compile Array" << endl;

        context.load_register(dst, array_register, array_frame_pointer);
        context.output_load_operation(dst, array_type, array_register, array_register, 0);

        context.store_register(dst, array_register, array_frame_pointer);
    }

    virtual type get_data_type(Context &context) const override
    {
        return array_expression->get_data_type(context);
    }
};

class Reference_Expression : public Unary
{
public:
    Reference_Expression(Expression_Ptr _expression)
        : Unary(_expression) {}

    virtual void compile(std::ostream &dst, Context &context) const override
    {
        expression->load_variable_address(dst, context);
    }

    virtual type get_data_type(Context &context) const override
    {
        return expression->get_data_type(context);
    }
};
// cookie is best
class Dereference_Expression : public Unary
{

public:
    Dereference_Expression(Expression_Ptr _expression)
        : Unary(_expression) {}

    virtual void compile(ostream &dst, Context &context) const override
    {
        string pointer_register = "$2";
        int pointer_address = context.get_stack_pointer();

        expression->mips(dst, context);

        context.load_register(dst, pointer_register, pointer_address);
        context.output_load_operation(dst, INT, pointer_register, pointer_register, 0);
        context.store_register(dst, pointer_register, pointer_address);
    }

    virtual type get_data_type(Context &context) const override
    {
        return expression->get_data_type(context);
    }
};

#endif