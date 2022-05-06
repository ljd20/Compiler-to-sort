#ifndef ast_primatives_hpp
#define ast_primatives_hpp

#include <string>
#include <ostream>
#include "context.hpp"
#include "ast_node.hpp"
using namespace std;


class Primatives :
    public Expression {};

class Integer:
    public Primatives{

        private:
            int value;

        public:
        Integer (int _value): 
        value(_value){}

        virtual void compile(ostream &dst, Context &context) const override{
            int stack_pointer = context.get_stack_pointer();
            
            string destination_reg = "$2";

            dst << "\t" << "li" << "\t" << "\t" << "$2" << ", " << value << endl 

            context.store_register(dst, destination_reg, stack_pointer);
        }
        virtual type datatype(Context &context) const override{
            return type(INT);
        };
        virtual double evaluate() const override{
            return value;
        };
    };


class Unsigned:
    public Primatives{
        private:

            unsigned int value;

        public:

            Unsigned (int _value):
            value(_value) {}

            virtual void compile(ostream &dst, Context &context) const override{
                int stack_pointer = context.get_stack_pointer();
            
                string destination_reg = "$2";

                dst << "\t" << "li" << "\t" << "\t" << "$2" << ", " << value << endl; 

                context.store_register(dst, destination_reg, stack_pointer);
        }
    virtual type datatype(Context &context) const override{
    return type(UNSIGNED_INT);
    };
    virtual double evaluate() const override{
    return value;
    };
};

class Double : 
    public Primitives{

	    private:
		    double value;

	    public: 
		
            Double (float _value): 
            value(_value) {}

            virtual void compile(ostream &dst, Context &context) const override{
			    int stack_pointer = context.get_stack_pointer();

			    string destination_reg = "$f0";

			    dst << "\t" << "li.d" << "\t" << "\t" << destination_reg << ", " << value << endl;

			    context.store_float_register(dst, destination_reg, stack_pointer);	
		}

		virtual type datatype(Context &context) const override { 
        return type(DOUBLE); 
        };
        virtual double evaluate() const override { 
        return value; 
        };
};

class Float : 
    public Primitives {

	    private:
		    float value;

	    public: 
		
            Float (float _value): 
            value(_value) {}

            virtual void compile(ostream &dst, Context &context) const override{
			    int stack_pointer = context.get_stack_pointer();

			    string destination_reg = "$f0";

			    dst << "\t" << "li.s" << "\t" << "\t" << destination_reg << ", " << value << endl;

			    context.store_float_register(dst, destination_reg, stack_pointer);	
		}

		virtual type datatype(Context &context) const override { 
        return type(FLOAT); 
        };
        virtual double evaluate() const override { 
        return value; 
        };
};

class Identifier : 
    public Primitives{

	    private:
		    string varname;

	    public: 
		
            Identifier (string _varname): 
            varname(_varname) {}

            virtual void compile(ostream &dst, Context &context) const override{
			    int destination_add = context.get_stack_pointer();

			    dst << "\t" << "# Access variable " << endl;

                string destination_reg = "$2";

                load_variable_add(dst, context);

                variable compile_variable = context.get_variable(varname);

                if (compile_variable.get_declaration_type() != ARRAY){
                    context.output_load_operation(dst, INT, destination_reg, destination_reg, 0);
				    context.store_register(dst, destination_reg, destination_add);
                }
            
            }

            virtual string get_variable_name() const override{
                return varname;
            };

			virtual void load_variable_address(ostream &dst, Context &context) const override{

			dst << "\t" << "# Load variable" << endl;

			int destination_add = context.get_stack_pointer();
			string destination_reg = "$2";
			variable compile_variable = context.get_variable(varname);

			if (compile_variable.get_variable_scope() == GLOBAL)
			{
				dst << "\t" << "la" << "\t" << "\t" << destination_reg << "," << varname << endl;
			}
			else 
			{
				dst << "\t" << "addiu" << "\t" << destination_reg << ",$30," << compile_variable.get_variable_add() << endl;
			}

			context.store_register(dst, destination_reg, destination_add);
		}

		virtual type get_data_type(Context &context) const { 
            return context.get_variable(varname).get_variable_type(); 
            };

		virtual type_definition get_type_definition(Context &context) const override { 
            return context.get_variable(varname).get_type_definition(); 
            };

		virtual bool get_pointer_capability(Context &context) const { 
            return context.get_variable(varname).get_pointer_capability(); 
            };
};

#endif