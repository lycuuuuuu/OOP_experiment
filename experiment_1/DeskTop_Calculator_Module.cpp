//
// Created by lyc on 2024/4/22.
//
#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;
enum Token_value{
    NAME, NUMBER, END, PLUS='+',
    MINUS='-', MUL='*', DIV='/',
    PRINT=';', ASSIGN='=', LP='(', RP=')'
};
Token_value curr_tok = PRINT;
namespace expr{double PlusOrMinus(bool);}
namespace term{double MulOrDiv(bool);}
namespace prim{double InputRecognize(bool);}
namespace get_token{Token_value get_token();}
namespace error{double error(const string&);}
map<string,double> table;

namespace expr{
    double PlusOrMinus(bool get){
        double left = term::MulOrDiv(get);
        for(;;)
            switch(curr_tok){
            case PLUS:
                left += term::MulOrDiv(true);
                break;
            case MINUS:
                left -= term::MulOrDiv(true);
                break;
            default:
                return left;
        }
    }
}

namespace term{
    double MulOrDiv(bool get){
        double left = prim::InputRecognize(get);
        for(;;)
            switch(curr_tok){
            case MUL:
                left *= prim::InputRecognize(true);
                break;
            case DIV:
                if(double d = prim::InputRecognize(true)){
                    left /= d;
                    break;
                }
            default:
                return left;
        }
    }
}

double number_value;
string string_value;
namespace prim{

    double InputRecognize(bool get){
        if(get) get_token::get_token();
        switch(curr_tok){
            case NUMBER:{
                double v = number_value;
                get_token::get_token();
                return v;
            }
            case NAME:{
                double& v = table[string_value];
                if(get_token::get_token() == ASSIGN)v = expr::PlusOrMinus(true);
                return v;
            }
            case MINUS:
                return -prim::InputRecognize(true);
            case LP:{
                double e = expr::PlusOrMinus(true);
                if(curr_tok!=RP)return error::error(") expected");
                get_token::get_token();
                return e;
            }
            default:
                return error::error("primary expected");
        }
    }
}

namespace get_token{
    Token_value get_token(){
        char ch;
        do{
            if(!cin.get(ch)) return curr_tok = END;
        }while(ch!='\n' && isspace(ch));

        switch(ch){
            case 0:
                return curr_tok=END;
            case '\n':
                return curr_tok=END;
            case '+':case '-':case '*':case '/':
            case ';':case '(':case ')':case '=':
                return curr_tok = Token_value(ch);
            case '0':case '1':case '2':case '3':
            case '4':case '5':case '6':case '7':
            case '8':case '9':case '.':
                cin.putback(ch);
                cin>>number_value;
                return curr_tok = NUMBER;
            default:
                if(isalpha(ch)){
                    string_value = ch;
                    while(cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
                    cin.putback(ch);
                    return curr_tok = NAME;
                }
                error::error("bad token");
                return curr_tok = PRINT;
        }
    }
}

int no_of_errors;
namespace error{
    double error(const string& s){
        no_of_errors++;
        cerr<<"error:"<<s<<"\n";
        return 1;
    }
}