#ifndef ast_node_hpp
#define ast_node_hpp

#include <iostream>
#include <string>
#include <ostream>
#include "context.hpp"
using namespace std;

// class Expression;

class Expression : public Node
{
public:
    virtual string get_variable_name() const
    {
        return 0;
    };

    virtual void load_variable_address(ostream &dst, Context &context) const {};

    virtual type get_data_type(Context &context) const
    {
        return type(INT);
    };

    virtual bool get_pointer(Context &context) const
    {
        return 0;
    };

    virtual type_definition get_type_definition(Context &context) const {};

    virtual double evaluate() const
    {
        return 0;
    };
};

typedef const Expression *Expression_Ptr;

#endif
/*
#ifndef ast_return_hpp
 #define ast_return_hpp

 #include <string>
 #include <iostream>

  class Returnfunct
     : public Node
 {
 private:
     NodePtr pass;

 public:
     Returnfunct(NodePtr _pass)
         : pass(_pass)
     {
     }
     virtual ~Returnfunct()
     {
         delete pass;
     }

     void mips(std::ostream &destreg, Context &context)
     {
         if (expression != NULL)
         {
             context.allocate_stack();
             pass->mips(context);
             context.deallocate_stack();
         }
     }
 };
*/
