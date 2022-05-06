#ifndef ast_operators_hpp
#define ast_operators_hpp

#include <string>
#include <ostream>
#include "ast_expression.hpp"
#include "ast_node.hpp"
#include "context.hpp"

using namespace std;

class Operator
    : public Expression
{

protected:
    Expression_Ptr left = NULL;
    Expression_Ptr right = NULL;

public:
    Operator(Expression_Ptr _left, Expression_Ptr _right) : left(_left), right(_right) {}

    virtual void compile(ostream &dst, Context &context) const override
    {
        type operator_type = left->get_data_type(context);

        int frame_pointer_1 = context.get_stack_pointer();

        string destination_register = "$2";
        left->mips(dst, context);

        context.allocate_stack();
        int frame_pointer_2 = context.get_stack_pointer();
        string temp_register = "$8";
        right->mips(dst, context);

        context.deallocate_stack();

        context.load_register(dst, destination_register, frame_pointer_1);
        context.load_register(dst, temp_register, frame_pointer_2);
        execute(dst, context, operator_type, destination_register, temp_register);
        context.store_register(dst, destination_register, frame_pointer_1);

        if (operator_type == FLOAT || operator_type == DOUBLE)
        {
            context.load_float_register(dst, "$f0", frame_pointer_1);
        }
    }

    virtual void execute(ostream &dst, Context &context, type type, string destination_register, std::string temprorary_register) const {}

    virtual type get_data_type(Context &context) const override
    {
        return type(left->get_data_type(context));
    };

    virtual bool get_pointer_capability(Context &context) const
    {
        return left->get_pointer_capability(context);
    };
};

class AddOperator : public Operator
{
public:
    AddOperator(Expression_Ptr _left, Expression_Ptr _right) : Operator(_left, _right) {}

    virtual void execute(ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {

        if (type == INT || type == UNSIGNED_INT)
        {
            dst << "\t"
                << "addu"
                << "\t" << destination_register << "," << destination_register << "," << temprorary_register << endl;
        }
        else if (type == FLOAT)
        {
            string temp_float_reg_1 = "$f0";
            string temp_float_reg_2 = "$f1";

            context.shift_to_float_reg(dst, destination_register, temp_float_reg_1);
            context.shift_to_float_reg(dst, temprorary_register, temp_float_reg_2);
            dst << "\t"
                << "add.s"
                << "\t" << temp_float_reg_1 << "," << temp_float_reg_1 << "," << temp_float_reg_2 << endl;
            context.shift_from_float_reg(dst, destination_register, temp_float_reg_1);
        }
        else if (type == DOUBLE)
        {
            string temp_float_reg_1 = "$f2";
            string temp_float_reg_2 = "$f0";

            context.shift_to_float_reg(dst, destination_register, temp_float_reg_1);
            context.shift_to_float_reg(dst, temprorary_register, temp_float_reg_2);

            dst << "\t"
                << "add.d"
                << "\t" << temp_float_reg_2 << "," << temp_float_reg_1 << "," << temp_float_reg_2 << endl;

            context.shift_from_float_reg(dst, destination_register, temp_float_reg_2);
        }
        else
        {
            cerr << "N?A data types" << endl;
            exit(1);
        }
    };

    virtual double evaluate() const override { return left->evaluate() + right->evaluate(); };
};

class MultOperator : public Operator
{
public:
    MultOperator(Expression_Ptr _left, Expression_Ptr _right) : Operator(_left, _right) {}

    virtual void execute(ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {

        if (type == INT || type == UNSIGNED_INT)
        {
            dst << "\t"
                << "multu"
                << "\t" << destination_register << "," << temprorary_register << endl;
            dst << "\t"
                << "mflo"
                << "\t" << destination_register << endl;
        }
        else if (type == FLOAT)
        {
            string temp_float_reg_1 = "$f0";
            string temp_float_reg_2 = "$f1";

            context.shift_to_float_reg(dst, destination_register, temp_float_reg_1);
            context.shift_to_float_reg(dst, temprorary_register, temp_float_reg_2);
            dst << "\t"
                << "mul.s"
                << "\t" << temp_float_reg_1 << "," << temp_float_reg_1 << "," << temp_float_reg_2 << endl;
            context.shift_from_float_reg(dst, destination_register, temp_float_reg_1);
        }
        else if (type == DOUBLE)
        {
            string temp_float_reg_1 = "$f2";
            string temp_float_reg_2 = "$f0";

            context.shift_to_float_reg(dst, destination_register, temp_float_reg_1);
            context.shift_to_float_reg(dst, temprorary_register, temp_float_reg_2);

            dst << "\t"
                << "mul.d"
                << "\t" << temp_float_reg_2 << "," << temp_float_reg_1 << "," << temp_float_reg_2 << endl;

            context.shift_from_float_reg(dst, destination_register, temp_float_reg_2);
        }
        else
        {
            cerr << "N?A data types" << endl;
            exit(1);
        }
    }

    virtual double evaluate() const override { return left->evaluate() * right->evaluate(); };
};

class DivOperator : public Operator
{
public:
    DivOperator(Expression_Ptr _left, Expression_Ptr _right) : Operator(_left, _right) {}

    virtual void execute(ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {

        if (type == INT || type == UNSIGNED_INT)
        {
            dst << "\t"
                << "divu"
                << "\t" << destination_register << "," << destination_register << "," << temprorary_register << endl;
            dst << "\t"
                << "mfho"
                << "\t" << destination_register << endl;
            dst << "\t"
                << "mflo"
                << "\t" << destination_register << endl;
        }
        else if (type == FLOAT)
        {
            string temp_float_reg_1 = "$f0";
            string temp_float_reg_2 = "$f1";

            context.shift_to_float_reg(dst, destination_register, temp_float_reg_1);
            context.shift_to_float_reg(dst, temprorary_register, temp_float_reg_2);
            dst << "\t"
                << "div.s"
                << "\t" << temp_float_reg_1 << "," << temp_float_reg_1 << "," << temp_float_reg_2 << endl;
            context.shift_from_float_reg(dst, destination_register, temp_float_reg_1);
        }
        else if (type == DOUBLE)
        {
            string temp_float_reg_1 = "$f2";
            string temp_float_reg_2 = "$f0";

            context.shift_to_float_reg(dst, destination_register, temp_float_reg_1);
            context.shift_to_float_reg(dst, temprorary_register, temp_float_reg_2);

            dst << "\t"
                << "div.d"
                << "\t" << temp_float_reg_2 << "," << temp_float_reg_1 << "," << temp_float_reg_2 << endl;

            context.shift_from_float_reg(dst, destination_register, temp_float_reg_2);
        }
        else
        {
            cerr << "N?A data types" << endl;
            exit(1);
        }
    }

    virtual double evaluate() const override { return left->evaluate() / right->evaluate(); };
};

class LessThanOperator : public Operator
{
public:
    LessThanOperator(Expression_Ptr _left, Expression_Ptr _right) : Operator(_left, _right) {}

    virtual void execute(ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {
        dst << "\t"
            << "slt "
            << "\t" << destination_register << "," << destination_register << "," << temprorary_register << endl;
    }
};

class GreaterThanOperator : public Operator
{
public:
    GreaterThanOperator(Expression_Ptr _left, Expression_Ptr _right) : Operator(_left, _right) {}

    virtual void execute(ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {
        dst << "\t"
            << "sgt "
            << "\t" << destination_register << "," << destination_register << "," << temprorary_register << endl;
    }
};

class GreaterThanEqOperator : public Operator
{
public:
    MoreThanEqOperator(Expression_Ptr _left, Expression_Ptr _right)
        : Operator(_left, _right) {}

    virtual void execute(ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {
        dst << "\t"
            << "sge "
            << "\t" << destination_register << "," << temprorary_register << "," << destination_register << endl;
    }
};

class LessThanEqOperator : public Operator
{
public:
    LessThanEqOperator(Expression_Ptr _left, Expression_Ptr _right)
        : Operator(_left, _right) {}

    virtual void execute(ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {
        dst << "\t"
            << "sle "
            << "\t" << destination_register << "," << temprorary_register << "," << destination_register << endl;
    }
};

class DoubleEqual : public Operator
{
public:
    DoubleEqual(Expression_Ptr _left, Expression_Ptr _right) : Operator(_left, _right) {}

    virtual void execute(ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {
        dst << "\t"
            << "xor "
            << "\t" << destination_register << "," << destination_register << "," << temprorary_register << endl;
        dst << "\t"
            << "sltiu "
            << "\t" << destination_register << "," << destination_register << "," << 1 << endl;
    }
};

class NotEqual : public Operator
{
public:
    NotEqual(Expression_Ptr _left, Expression_Ptr _right) : Operator(_left, _right) {}

    virtual void execute(ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {
        dst << "\t"
            << "xor "
            << "\t" << destination_register << "," << destination_register << "," << temprorary_register << endl;
        dst << "\t"
            << "sltu "
            << "\t" << destination_register << "$0," << destination_register << "," << endl;
    }
};

class BitAndOperator : public Operator
{
public:
    BitAndOperator(Expression_Ptr _left, Expression_Ptr _right) : Operator(_left, _right) {}

    virtual void execute(ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {
        dst << "\t"
            << "and "
            << "\t" << destination_register << "," << destination_register << "," << temprorary_register << endl;
    }
};

class BitOrOperator : public Operator
{
public:
    BitOrOperator(Expression_Ptr _left, Expression_Ptr _right) : Operator(_left, _right) {}

    virtual void execute(ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {
        dst << "\t"
            << "or "
            << "\t" << destination_register << "," << destination_register << "," << temprorary_register << endl;
    }
};

class BitXorOperator : public Operator
{
public:
    BitXorOperator(Expression_Ptr _left, Expression_Ptr _right) : Operator(_left, _right) {}

    virtual void execute(ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {
        dst << "\t"
            << "xor "
            << "\t" << destination_register << "," << destination_register << "," << temprorary_register << endl;
    }
};

class LeftBitShift : public Operator
{
public:
    LeftBitShift(Expression_Ptr _left, Expression_Ptr _right) : Operator(_left, _right) {}

    virtual void execute(ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {
        dst << "\t"
            << "sllv "
            << "\t"
            << "\t" << destination_register << "," << destination_register << "," << temprorary_register << endl;
    }
};

class RightBitShift : public Operator
{
public:
    RightBitShift(Expression_Ptr _left, Expression_Ptr _right) : Operator(_left, _right) {}

    virtual void execute(std::ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {
        if (type == INT)
        {
            dst << "\t"
                << "srav "
                << "\t"
                << "\t" << destination_register << "," << destination_register << "," << temprorary_register << endl;
        }
        else
        {
            dst << "\t"
                << "sral "
                << "\t"
                << "\t" << destination_register << "," << destination_register << "," << temprorary_register << endl;
        }
    }
};

class LogAndOperator : public Operator
{

public:
    LogAndOperator(Expression_Ptr _left, Expression_Ptr _right) : Operator(_left, _right) {}

    virtual void execute(std::ostream &dst, Context &context, type type, string destination_register, string temprorary_register) const override
    {
        context.make_label("LOGICAL_AND");
        string return_label = context.get_function_return_label();

        string destination_name = "$2";
        int destination_address = context.get_stack_pointer();

        left->mips(dst, context);
        context.load_register(dst, destination_name, destination_address);

        dst << "\t"
            << "beq "
            << "\t" << destination_register << ","
            << "$0"
            << "," << return_label << endl;

        context.allocate_stack();
        int frame_pointer_temp_reg = context.get_stack_pointer();

        string temp_register_1 = "$8";
        right->mips(dst, context);

        context.load_register(dst, temp_register_1, frame_pointer_temp_reg);
        context.deallocate_stack();

        dst << "\t"
            << "beq "
            << "\t" << temp_register_1 << ","
            << "$0"
            << "," << return_label << endl;

        dst << "\t"
            << "addiu "
            << "\t"
            << "\t" << destination_register << ","
            << "$0"
            << "," << 1 << endl;

        context.store_register(dst, destination_name, destination_address);
    }
};

class LogOrOperator : public Operator
{

public:
    LogOrOperator(Expression_Ptr _left, Expression_Ptr _right) : Operator(_left, _right) {}

    virtual void execute(ostream &dst, Context &context, type type, std::string destination_register, std::string temprorary_register) const override
    {
        string return_label_1 = context.make_label("LOGICAL_OR");
        string return_label_2 = context.make_label("LOGICAL_OR");

        string destination_name = "$2";
        int destination_address = context.get_stack_pointer();

        left->mips(dst, context);
        context.load_register(dst, destination_name, destination_address);

        dst << "\t"
            << "bne "
            << "\t"
            << "\t" << destination_register << ","
            << "$0"
            << "," << return_label_1 << std::endl;

        context.allocate_stack();
        int frame_pointer_temp_reg = context.get_stack_pointer();

        string temp_register_1 = "$8";
        right->mips(dst, context);

        context.load_register(dst, temp_register_1, frame_pointer_temp_reg);
        context.deallocate_stack();

        dst << "\t"
            << "beq "
            << "\t" << temp_register_1 << ","
            << "$0"
            << "," << return_label_2 << std::endl;

        dst << "\t"
            << "addiu "
            << "\t" << destination_register << ","
            << "$0"
            << "," << 1 << std::endl;

        dst << "\t" << return_label_1 << ":" << endl;
        dst << "\t"
            << "addiu "
            << "\t" << destination_register << ","
            << "$0"
            << "," << 1 << std::endl;
        dst << "\t" << return_label_2 << ":" << endl;

        context.store_register(dst, destination_name, destination_address);
    }
};

#endif
