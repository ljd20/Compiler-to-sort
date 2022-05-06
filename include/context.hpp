#ifndef context_hpp
#define context_hpp

#include <string>
#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>
#include <regex>
#include <deque>
#include <map>
#include <cassert>
#include <memory>
#include <stack>

using namespace std;

// class Expression;
// class Statement;

enum context_scope
{
    GLOBAL,
    LOCAL
};

enum dectype
{
    NORMAL,
    FUNCTION,
    ARRAY,
    POINTER,
    STRUCT
};

enum type
{
    INT,
    UNSIGNED_INT,
    FLOAT,
    CHAR,
    DOUBLE,
    STRING,
    NONE,
    VOID
};

struct attributes
{
    string type;
    int frameaddress;
};

class Node
{

public:
    virtual ~Node()
    {
        virtual void mips(ostream & dst, Context & context) const
        {
            // cerr << "node thing doesn't compile" << endl;
        }
    }
};

class typedefine
{

private:
    type vartype;
    bool pointer = 0;

    unsigned int pointer_tracker = 0;
    unsigned int array_tracker = 0;

public:
    typedefine(type _vartype)
        : vartype(_vartype) {}

    typedefine(string _pointerflag, typedefine _pointertype)
    {
        if (_pointerflag == "POINTER")
        {
            pointer = 1;
            vartype = _pointertype.get_vartype();
            pointer_tracker++;
        }
    }

    type get_vartype()
    {
        return vartype;
    }

    unsigned int get_array_tracker()
    {
        return array_tracker;
    }

    unsigned int get_pointer_tracker()
    {
        return pointer_tracker;
    }

    void increment_array_tracker()
    {
        array_tracker++;
    }

    void increment_pointer_tracker()
    {
        pointer_tracker++;
    }

    void decrement_array_tracker()
    {
        array_tracker--;
    }

    void decrement_pointer_tracker()
    {
        if (pointer_tracker != 0)
        {
            array_tracker--;
        }
        else
        {
            pointer_tracker--;
        }
    };

    void set_pointer()
    {
        pointer = 1;
    }
    bool get_pointer()
    {
        return pointer;
    }
};

class variable
{

private:
    int var_address;
    context_scope variable_scope = GLOBAL;
    dectype variable_declaration;
    typedefine vartype;
    bool pointer = 0;

public:
    variable(int _var_address, context_scope _variable_scope, dectype _variable_declaration, typedef _vartype, bool _pointer)
        : var_address(_var_address), variable_scope(_variable_scope), variable_declaration(_variable_declaration), vartype(_vartype), pointer(_pointer) {}

    int get_var_address()
    {
        return var_address;
    }

    context_scope get_variable_scope()
    {
        return variable_scope;
    }

    type get_vartype()
    {
        return vartype.get_vartype();
    }

    typedefine get_typedef()
    {
        return vartype;
    }

    dectype get_decltype()
    {
        return variable_declaration;
    }

    bool get_pointer()
    {
        return pointer;
    }

    string get_storage_type()
    {
        if (vartype.get_vartype() == INT || vartype.get_vartype() == DOUBLE)
        {
            return "number";
        }
        else
        {
            return "word";
        }
    }
};

static context_scope scope_tracker;
typedef map<string, variable *> type_mapping;
typedef map<int, variable *> variable_address_mapping;

class Context
{
private:
    type_mapping *ContextTracker = new type_mapping();
    variable_address_mapping *address_tracker = new variable_address_mapping();

    stack<type_mapping *> context_scope_stack_tracker;
    stack<int> context_scope_frame_pointer;

    int label_counter = 0;
    int stack_pointer = 0;
    int register_counter = 0;
    string main_function_return_label;

    stack<string> break_stack;
    stack<string> continue_stack;

    deque<Expression *> switch_statements_tracker;
    deque<string> switch_label_tracker;

    map<string, string> label_variables;
    map<string, string> label_declarations;

public:
    bool check_function_declared(string Function_Name)
    {
        if ((*ContextTracker).count(Function_Name))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void add_label_variable(string label, string variable)
    {
        label_variable[variable] = label;
    };

    void add_label_declaration(string variable, string declaration)
    {
        label_declarations[variable] = declaration;
    };

    void add_case_statement(Expression *case_statement, string case_label)
    {
        switch_statements_tracker.push_back(case_statement);
        switch_label_tracker.push_back(case_label);
    }

    void add_case_label(string case_label)
    {
        switch_label_tracker.push_back(case_label);
    }

    string get_case_label()
    {
        return switch_label_tracker.front();
    }

    int get_case_label_size()
    {
        return switch_label_tracker.size();
    }

    void remove_case_statement()
    {
        switch_statements_tracker.pop_front();
    }

    void remove_label_statement()
    {
        switch_label_tracker.pop_front();
    }

    void add_break_label(string break_label)
    {
        break_stack.push(break_label);
    }

    void add_continue_label(string continue_label)
    {
        continue_stack.push(continue_label);
    }

    stack<string> get_break_label()
    {
        return break_stack;
    }

    stack<string> get_continue_label()
    {
        return continue_stack;
    }

    void remove_break_label()
    {
        break_stack.pop();
    }

    void remove_continue_label()
    {
        continue_stack.pop();
    }

    string get_function_return_label()
    {
        return main_function_return_label;
    }

    void set_main_return_label(string return_label)
    {
        label_counter++;
        main_function_return_label = return_label + "_" + to_string(label_counter);
    }

    string make_label(string return_label)
    {
        label_counter++;
        return return_label + "_" + to_string(label_counter);
    }

    context_scope get_context_scope()
    {
        return scope_tracker;
    }

    void set_LOCAL()
    {
        scope_tracker = LOCAL;
    }

    void set_GLOBAL()
    {
        scope_tracker = GLOBAL;
    }

    void expand_context_scope()
    {
        context_scope_frame_pointer.push(stack_pointer);
        context_scope_stack_pointer.push(ContextTracker);
        ContextTracker = new type_mapping(*ContextTracker);
    }

    void shrink_context_scope()
    {
        delete ContextTracker;
        stack_pointer = context_scope_frame_pointer.top();
        ContextTracker = context_scope_stack_tracker.top();
        context_scope_frame_pointer.pop();
        context_scope_stack_tracker.pop();
    }

    void allocate_stack()
    {
        register_counter++;
        stack_pointer -= 4;
    }

    void deallocate_stack()
    {
        if (register_counter != 0)
        {
            stack_pointer += 4;
            register_counter--;
        }
    }

    int get_stack_pointer()
    {
        return stack_pointer;
    }

    void load_register(ostream &dst, string register_name, int memory_location)
    {
        dst << "\t"
            << "lw"
            << "\t"
            << "\t" << register_name << "," << memory_location << "($30)" << endl;
    }

    void store_register(ostream &dst, string register_name, int memory_location)
    {
        dst << "\t"
            << "sw"
            << "\t"
            << "\t" << register_name << "," << memory_location << "($30)" << endl;
    }

    void output_load_operation(ostream &dst, string load_type, string register_1, string register_2, int frame_offset)
    {
        dst << "\t"
            << "lw"
            << "\t"
            << "\t" << register_1 << "," << frame_offset << "(" << register_2 << ")" << endl;
    }

    void output_store_operation(ostream &dst, string load_type, string register_1, string register_2, int frame_offset)
    {
        dst << "\t"
            << "sw"
            << "\t"
            << "\t" << register_1 << "," << frame_offset << "(" << register_2 << ")" << endl;
    }

    variable new_variable(string variable_name, typedefine vartype, dectype vardecltype, bool pointer = 0, int variable_size = 1)
    {
        if (scope_tracker == LOCAL)
        {
            if (vardecltype == ARRAY)
            {
                vartype.decrement_pointer_tracker();
            }
            stack_pointer -= variable_size * (4);
        }

        if (pointer)
        {
            (*ContextTracker)[variable_name] = new variable(stack_pointer, scope_tracker, vardecltype, vartype, pointer);
            (*ContextTracker)[variable_name] = new variable(stack_pointer, scope_tracker, vardecltype, vartype);
        }
        return *((*ContextTracker)[variable_name]);
    }

    variable get_variable_address(int address)
    {
        if ((*address_tracker).count(address))
        {
            return *((*address_tracker)[address]);
        }
    }

    variable get_variable(string variable_name)
    {
        if ((*ContextTracker).count(variable_name))
        {
            return *((*ContextTracker)[variable_name]);
        }
    }

    bool get_pointer(string variable_name)
    {
        return (*ContextTracker)[variable_name]->get_pointer();
    }

    void pointer_shift(ostream &dst, typedefine vartype, int stack_pointer)
    {
        cerr << vartype.get_pointer() << endl;

        if ((vartype.get_pointer()) && (vartype.get_vartype() == INT))
        {
            dst << "\t"
                << "sll"
                << "\t"
                << "\t"
                << "$2"
                << ","
                << "$2"
                << "," << 2 << endl;
            store_register(dst, "$2", stack_pointer);
        }
    }

    void make_new_arguement(string arguement_name, typedefine arguement_type, dectype arguement_declaration, int arguement_address, bool pointer = 1)
    {
        (*ContextTracker)[arguement_name] = new variable(arguement_address, LOCAL, arguement_declaration, arguement_type, pointer);
    }

    void shift_to_float_reg(ostream &dst, string int_register, string float_register)
    {
        dst << "\t"
            << "mtc1"
            << "\t" << int_register << "," << float_register << endl;
    }

    void shift_from_float_reg(ostream &dst, string int_register, string float_register)
    {
        dst << "\t"
            << "mfc1"
            << "\t" << int_register << "," << float_register << endl;
    }

    void load_float_register(ostream &dst, string register_name, string memory_location)
    {
        dst << "\t"
            << "lwc1"
            << "\t" << register_name << "," << memory_location << "($30)" << endl;
    }

    void store_float_register(ostream &dst, string register_name, string memory_location)
    {
        dst << "\t"
            << "swc1"
            << "\t" << register_name << "," << memory_location << "($30)" << endl;
    }
};

#endif