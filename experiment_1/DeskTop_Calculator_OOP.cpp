//
// Created by lyc on 2024/4/22.
//
#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;

enum Token_value {
    NAME, NUMBER, END, PLUS='+',
    MINUS='-', MUL='*', DIV='/',
    PRINT=';', ASSIGN='=', LP='(', RP=')',
};
Token_value curr_tok = PRINT;
map<string,double> table;

class expr{
public:
    double PlusOrMinus(bool get);
};
class term{
public:
    double MulOrDiv(bool get);
};
class prim{
public:
    double InputRecognize(bool get);
};
class get_token{
public:
    Token_value getToken();
};
class error{
public:
    double Error(const string&s);
};

double expr::PlusOrMinus(bool get) {
    term t;
    double left = t.MulOrDiv(get);
    for(;;) {
        switch (curr_tok){
            case PLUS:
                left += t.MulOrDiv(true);
                break;
            case MINUS:
                left -= t.MulOrDiv(true);
                break;
            default:
                return left;
        }
    }
}

double term::MulOrDiv(bool get) {
    prim p;
    error er;
    double left = p.InputRecognize(get);
    for(;;) {
        switch (curr_tok){
            case MUL:
                left *= p.InputRecognize(true);
                break;
            case DIV:
                if (double d = p.InputRecognize(true)) {
                    left /= d;
                    break;
                }
                return er.Error("divide by 0");
            default:
                return left;
        }
    }
}
double number_value;
string string_value;
double prim::InputRecognize(bool get) {
    get_token g;
    expr ex;
    error er;
    prim p;
    if (get) g.getToken();

    switch(curr_tok) {
        case NUMBER: {              //浮点常量
            double v = number_value;
            g.getToken();
            return v;
        }
        case NAME: {
            double& v = table[string_value];
            if (g.getToken() == ASSIGN) v = ex.PlusOrMinus(true);
            return v;
        }
        case MINUS:            //一元
            return -p.InputRecognize(true);
        case LP: {                //吃掉‘）’
            double e = ex.PlusOrMinus(true);
            if (curr_tok != RP) return er.Error(" ) expected");
            get_token();
            return e;
        }
        default:
            return er.Error("primary expected");
    }
}

Token_value get_token::getToken() {
    char ch;

    do { // 低级输入，改进输入
        if(!cin.get(ch)) return curr_tok = END;
    } while(ch != '\n' && isspace(ch));

    switch(ch) {
        error er;
        case 0:
            return curr_tok=END;
        case '\n':
            return curr_tok=PRINT;
        case '+':
        case '-':
        case '*':
        case '/':
        case ';':
        case '(':
        case ')':
        case '=':
            return curr_tok = Token_value(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            cin.putback(ch);
            cin>>number_value;
            return curr_tok = NUMBER;
        default:
            if (isalpha(ch)) {
                string_value = ch;
                while(cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
                cin.putback(ch);
                return curr_tok = NAME;
            }
            er.Error("bad token");
            return curr_tok = PRINT;
    }
}

int no_of_errors;
double error::Error(const string&s) {
    no_of_errors ++;
    cerr<<"error: "<<s<<'\n';
    return 1;
}

