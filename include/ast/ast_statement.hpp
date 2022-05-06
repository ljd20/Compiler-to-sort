#ifndef ast_primatives_hpp
#define ast_primatives_hpp

#include <string>
#include <ostream>
using namespace std;
#include "context.hpp"

class Compound:
    public Statement{

        private:

            vector<Statement*>* statement_list;
            vector<Declaration*>* declaration_list;

        public:

            Compound (vector<Declaration*>* _declaration_list = NULL, vector<Statement*>* _statement_list = NULL)
            : statement_list (_statement_list), declaration_list (_declaration_list){}

            virtual void compile(ostream &dst, Context &context) const override{
                context.expand_context_scope();
                if(declaration_list != NULL){
                    for(auto declaration = declaration_list->begin(); declaration != declaration_list->end(); declaration++){
                        (*declaration)->mips(dst, context);
                    }
                }

                if(statement_list != NULL){
                    for(auto statement = statement_list->begin(); statement != statement_list->end(); statement++){
                        (*statement)->mips(dst, context);
                    }
                }

                context.shrink_context_scope();
            }       
    };

class ExpressionStatement :
    public Statement{
        
        private:

            Expression * expression;
        
        public:

            ExpressionStatement (Expression * _expression = NULL)
            : expression (_expression) {}

            virtual void compile (ostream &dst, Context &context) const override{
                if(expression != NULL){
                    context.allocate_stack();
                    expression->mips(dst, context);
                    context.deallocate_stack();
                }
            }


            
    };

class Continue :
    public Statement{

        private:

        public:

            Continue(){}

            virtual void compile(ostream &dst, Context &context) const override {
                dst<< "\t" << "b" << "\t" << "\t" << context.get_continue_label().top() << endl;
            }
    };

class Break :
    public Statement{

        private:

        public:

            Break(){}

            virtual void compile(ostream &dst, Context &context) const override {
                dst<< "\t" << "b" << "\t" << "\t" << context.get_break_label().top() << endl;
            }
    };

class While:
    public Statement{

        private:
            Expression * ConditionExpression;
            Statement * TrueStatement;

        public:
            While (Expression * _ConditionExpression, Statement * _TrueStatement)
            : ConditionExpression(_ConditionExpression), TrueStatement(_TrueStatement){}

            virtual void compile(ostream &dst, Context &context) const override{
                string START_label = context.make_label("START_WHILE");
                string FINISH_label = context.make_label("FINISH_WHILE");

                dst << START_label << ":" << endl;

                context.allocate_stack();
                string temp_reg1 = "$2";
                int frame_pointer1 = context.get_stack_pointer();
                context.load_register(dst, temp_reg1, frame_pointer1);

                condition_expression->mipsr(dst, context);
                context.deallocate_stack();

                dst << "\t" << "beq " << "\t" << "$0" << "," << temp_reg1 << "," << FINISH_label << endl;

			    true_statement->mips(dst, context);

			    dst << "\t" << "b " << "\t"  << "\t" << START_label << endl;
			    dst << "\t" << FINISH_label << ":" <<endl;
            }
    };

class For:
    public Statement{

        private:
            Expression * InitExpression;
            Expression * ConExpression;
            Expression * UpdateExpression;
            Statement * TrueStatement;

        public:
            For (Expression * _InitExpression, Expression * _ConStatement, Expression * _UpdateExpression, Statement * _TrueStatement)
            : InitExpression(_InitExpression), ConExpression(_ConExpression), UpdateExpression(_UpdateExpression), TrueStatement(_TrueStatement){}

            virtual void compile(ostream &dst, Context &context) const override{
                string START_label = context.make_label("START_FOR");
                string FINISH_label = context.make_label("FINISH_FOR");

                if(InitExpression != NULL) {
                    context.allocate_stack();
                    InitExpression->mipsr(dst, context);
                    context.deallocate_stack();
                }

                dst << endl;
                dst << START_label << ":" << endl;
                dst << endl;


                context.allocate_stack();
                string temp_conreg = "$8";
                int stack_pointer2 = context.get_stack_pointer();

                if(ConExpression != NULL){
                    ConExpression->mips(dst, context);
                }

                context.load_register(dst, temp_conreg, stack_pointer2);

                context.deallocate_stack();

                dst << "\t" << "beq " << "\t" << "$0" << "," << temp_conreg << "," << FINISH_label << endl;

			    true_statement->mips(dst, context);

                if(UpdateExpression != NULL){
                    context.allocate_stack();
                    string TempUpdateReg = "$8";
                    UpdateExpression->mips(dst, context);
                    context.deallocate_stack();
                }

			    dst << "\t" << "b " << "\t"  << "\t" << START_label << endl;
                dst << endl;
			    dst << "\t" << FINISH_label << ":" <<endl;
                dst << endl;
            }
    };

class IfStatement:
    public Statement{

        private:
            Expression * CondExpression;
            Statement * TrueStatement;

        public:
            IfStatement (Expression * _CondExpression, Statement * _TrueStatement)
            : CondExpression (_CondExpression), TrueStatement (_TrueStatement) {}

            virtual void compile (ostream &dst, Context &context) const override{
                context.allocate_stack();
                string temp_reg1 = "$2";
                CondExpression->mips(dst, context);
                context.deallocate_stack();
                string if_return_label = context.make_label("IF_RETURN");

                dst << "\t" << "beq " << "\t" << "$0" << "," << temp_reg1 << "," << if_return_label << endl;
                TrueStatement->mips(dst, context);
                dst << if_return_label << ":" << endl;

            }
    };

class IfElse:
    public Statement{

        private:
            Expression * CondExpression;
            Statement * TrueStatement;
            Statement * FalseStatement;

        public:
            IfElse (Expression * _CondExpression, Statement * _TrueStatement, Statement * _FalseStatement)
            : CondExpression (_CondExpression), TrueStatement (_TrueStatement), FalseStatement (_FalseStatement) {}

            virtual void compile (ostream &dst, Context &context) const override{

                context.allocate_stack();
                string temp_reg1 = "$2";
                int frame_pointer1 = context.get_stack_pointer();
                CondExpression->mips(dst, context);
                context.load_register(dst, temp_reg1, frame_pointer1);
                context.deallocate_stack();
                string if_return_label = context.make_label("IF_RETURN");
                string else_return_label = context.make_label("ELSE_RETURN");

                dst << "\t" << "beq " << "\t" << "$0" << "," << temp_reg1 << "," << if_return_label << endl;
                TrueStatement->mips(dst, context);
                dst << "\t" << "b " << "\t" << "\t" << else_return_label << endl;
                dst<< endl;
                dst << if_return_label << ":" << endl;
                FalseStatement->mips(dst, context);
                dst<< endl;
                dst << else_return_label << ":" << endl;
            }
    };

class JumpStatement:
    public Statement{

        private:
            Expression * expression;
        
        public:
            JumpStatement (Expression * _expression = NULL)
            : expression (_expression){}
        
        virtual void compile(ostream &dst, Context &context) const override{
            if(expression != NULL){
                context.allocate_stack();
                int DestinationAddress = context.get_stack_pointer();
                expression->mips(dst, context);
                context.deallocate_stack();
                DestinationAddress = context.get_stack_pointer();
                if(context.get_variable_addresss(DestinationAddress).get_pointer_capability()){}
                dst << "\t" << "b " << "\t"  << "\t" << context.get_function_return_label() << endl;
            }
        }
    };

class Switch:
    public Statement{

        private:
            Expression * expression;
            Statement * SwitchStatement;

        public:
            Switch (Expression * _expression, Statement * _SwitchStatement)
            : Expression(_expression), SwitchStatement(_SwitchStatement){}

            virtual void compile(ostream &dst, Context &context) const override{
                dst<<endl;
                dst << "#  Switch  #" << endl;

                string START_label = context.make_label("START_SWITCH");
                string FINISH_label = context.make_label("FINISH_SWITCH");

                context.add_break_label(FINISH_label):

                stringstream ss;
                SwitchStatement->mips(ss, context);

                
                context.allocate_stack();
                string SwitchRegister = "$2";
                int switch_StackPointer = context.get_StackPointer();
                expression->(dst, context);

                context.allocate_stack();
                string CaseRegister = "$8";
                int case_StackPointer = context.get_StackPointer();

                while(context.get_CaseStatement_size() !=0){
                    Expression * CaseStatement = context.get_CaseStatement();
				    CaseStatement->mips(dst, context);
				    :string CaseLabel = context.get_CaseLabel();

				    context.load_register(dst, SwitchRegister, switch_StackPointer);
				    context.load_register(dst, CaseRegister, case_StackPointer);

				    dst << "\t" << "beq" << "\t" << SwitchRegister << "," << CaseRegister << "," << CaseLabel << endl;

				    context.remove_CaseStatement();
				    context.remove_LabelStatement();

                }

                if(context.get_CaseLabel_size() != 0){
				    dst << "\t" << "b " << "\t"  << "\t" << context.get_CaseLabel() << endl;
				    context.remove_LabelStatement();
			    }

                dst << "\t" << "b " << "\t"  << "\t" << FINISH_label << endl;
                dst << ss.str() << endl;
                dst << FINISH_label << ":" << endl;

                context.deallocate_stack();
                context.deallocate_stack();
                context.remove_break_label();

                }
    };

class Case : 
    public Statement{
	    private:
		    Expression * expression;
		    Statement * SwitchStatements;

        public:
            Case( Expression * _expression, Statement * _SwitchStatements)
            : expression(_expression), SwitchStatements(_SwitchStatements) {}

            virtual void compile(std::ostream &dst, Context& context) const override{
                dst << "Case" << endl;
                
                string CaseLabel = context.make_label("CASE");
                context.add_CaseStatements(expression, CaseLabel);
                dst << CaseLabel << ":" << endl;
                SwitchDtatements->mips(dst, context);
            }
};

class Default : 
    public Statement{
        private:
            Statement* DefaultStatements;

        public:
            Default(Statement* _DefaultStatements)
            : DefaultStatements(_DefaultStatements) {}

            virtual void compile(ostream &dst, Context& context) const override{
                dst << "Default" << endl;
                string DefaultLabel = context.make_label("DEFAULT");
                context.add_CaseLabel(DefaultLabel);
                dst << DefaultLabel << ":" << endl;
                DefaultStatements->mips(dst, context);
            }
};

#endif