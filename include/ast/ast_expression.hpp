#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <ostream>
#include "context.hpp"
#include "ast_node.hpp"
using namespace std;


class SizeofTypeExpression : 
    public Expression{
        private:
            type sizeofType;
            
        public:
            SizeofTypeExpression(type_definition _sizeofType) 
            : sizeofType(_sizeofType.get_variable_type()) {}

            virtual void compile(ostream &dst, Context &context) const override{
                int stack_pointer = context.get_stack_pointer();
                string DestinationRegister = "$2";

                if(sizeofType == INT || sizeofType == FLOAT){
                    dst << "\t" << "li" << "\t" << "\t" << "$2" << ", " << 4 << endl;
                }
                else if(sizeofType == VOID || sizeofType == CHAR){
                    dst << "\t" << "li" << "\t" << "\t" << "$2" << ", " << 1 << endl;
                }
                else if(sizeofType == DOUBLE || sizeofType == FLOAT||sizeofType == UNSIGNED_INT)
                {
                    dst << "\t" << "li" << "\t" << "\t" << "$2" << ", " << 8 << std::endl;
                }

                context.store_register(dst, DestinationRegister, stack_pointer);	
            }
    };

class SizeofVariableExpression : 
    public Expression{

        private:
            string VariableName;

        public:
            SizeofVariableExpression(string _VariableName) 
            : VariableName(_VariableName) {}

            virtual void compile(ostream &dst, Context &context) const override{
                type VariableType = context.get_variable(VariableName).get_VariableType();

                int stack_pointer = context.get_stack_pointer();
                string DestinationRegister = "$2";

                if(VariableType == INT || VariableType == FLOAT){
                    dst << "\t" << "li" << "\t" << "\t" << "$2" << ", " << 4 << endl;
                }
                else if(VariableType == VOID)
                {
                    dst << "\t" << "li" << "\t" << "\t" << "$2" << ", " << 0 << endl;
                }
                else if(VariableType == CHAR)
                {
                    dst << "\t" << "li" << "\t" << "\t" << "$2" << ", " << 1 << endl;
                }
                else if(VariableType == DOUBLE ||VariableType == FLOAT||VariableType == UNSIGNED_INT){
                    dst << "\t" << "li" << "\t" << "\t" << "$2" << ", " << 8 << sendl;
                }

                context.store_register(dst, DestinationRegister, stack_pointer);	
            }
    };


    class Decrement : 
    public Expression{

        protected:
            Expression * left=NULL;
            Expression * right=NULL;

        public:
            Decrement (Expression* _left, Expression* _right) : left (_left), right (_right) {}

            virtual void execute(ostream &dst, Context &context, type type, string DestinationRegister, string TemporaryRegister) const {}

            virtual void compile(ostream &dst, Context &context) const override
            {
                type operator_type = INT;

                int frame_pointer_1 = context.get_stack_pointer(); 

                string temp_register = "$2";
                left->mips(dst, context);

                context.allocate_stack(); 
                int frame_pointer_2 = context.get_stack_pointer();
                string DestinationRegister = "$8";
                right->mips(dst, context);

                context.deallocate_stack(); 

                context.load_register(dst, temp_register, frame_pointer_1);
                context.load_register(dst, DestinationRegister, frame_pointer_2);

                decrement(dst, context, OperatorType, temp_register, DestinationRegister);

                context.store_register(dst, temp_register, frame_pointer_1);
            }

            void decrement(ostream &dst, Context &context, type type, string DestinationRegister, string TemproraryRegister) const{
                dst << "\t" << "subu" << "\t" << DestinationRegister << "," << DestinationRegister << "," << TemproraryRegister << endl;
            }	
    };

class Assignment_Expression : 
    public Expression{
        protected:
            Expression* left_value;
            Expression* expression;
                
        public:
            Assignment_Expression (Expression* _left_value, Expression* _expression) 
            : left_value (_left_value), expression (_expression) {}

            virtual void compile(std::ostream &dst, Context &context) const override{
                dst << "Triggered 4" << endl;
            }
    };

class Direct_Assignment : 
public Assignment_Expression{
	public:
		Direct_Assignment (Expression* _left_value, Expression* _expression) 
        : Assignment_Expression (_left_value, _expression) {}

		virtual void compile(std::ostream &dst, Context& context) const override{
			type operator_type = INT; 

			int frame_pointer_1 = context.get_stack_pointer();

			std::string DestinationRegister = "$2";
			left_value->load_variable_address(dst, context);		

			dst << "\t" << "# Compile Direct Assignment Expression" << endl; 

			context.allocate_stack();

			int frame_pointer_2 = context.get_stack_pointer(); 
			string temp_register_1 = "$8";
			expression->mips(dst, context);

			context.deallocate_stack();

			context.load_register(dst, DestinationRegister, frame_pointer_1);
			context.load_register(dst, temp_register_1, frame_pointer_2);
			context.output_store_operation(dst, operator_type, temp_register_1, DestinationRegister, 0);

			context.store_register(dst, temp_register_1, frame_pointer_1);
		}

        virtual type get_data_type(Context& context) const override { 
            left_value->get_data_type(context); 
            };
};

#endif