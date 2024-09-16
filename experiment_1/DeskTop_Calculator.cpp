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
//最后一次调用get_token（）的值可以在curr_tok中找到
Token_value curr_tok = PRINT;

double expr(bool);//加减
double term(bool);//乘除
double prim(bool);//括号
Token_value get_token();//读取输入字符
double error(const string&);//报错
map<string, double> table;


// expr处理加减，一直到不是加减返回left
double expr(bool get) {
    double left = term(get);//这里和下面调用term，是因为乘除优先级高于加减（没有括号的情况下）
    for(;;) {
        switch (curr_tok){
            case PLUS://加
                left += term(true);
                break;
            case MINUS://减
                left -= term(true);
                break;
            default:
                return left;//一直到读取的输入不是加减时才返回计算结果
        }
    }
}

// 乘除，和expr思想相同
double term(bool get) {
    double left = prim(get);//调用prim是因为有括号优先级大于无括号
    for(;;) {
        switch (curr_tok){
            case MUL://乘
                left *= prim(true);
                break;
            case DIV://除
                if (double d = prim(true)) //这里防止除数为0
                {
                    left /= d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;
        }
    }
}

double number_value;//存放用户输入的浮点数
string string_value;//存放用户输入的变量名
// prim处理初等项的方式很像expr和term
double prim(bool get) {           //处理初等项
    if (get) get_token();

    switch(curr_tok) {
        case NUMBER: {              //浮点常量
            double v = number_value;
            get_token();
            return v;
        }
        case NAME: {
            double& v = table[string_value];
            if (get_token() == ASSIGN) v = expr(true);
            return v;
        }
        case MINUS:
            return -prim(true);
        case LP: {
            double e = expr(true);
            if (curr_tok != RP) return error(" ) expected");
            get_token();
            return e;
        }
        default:
            return error("primary expected");
    }
}
//expr调用term,term调用prim,prim调用expr，循环调用实现递归，因此不需要for结构，也不需要函数递归

Token_value get_token() {
    char ch;

    do {
        if(!cin.get(ch)) return curr_tok = END;
    } while(ch != '\n' && isspace(ch));

    switch(ch) {
        case 0:
            return curr_tok=END;
        case '\n':
            return curr_tok=PRINT;

        //这些输入啥就是啥，一个一个读
        case '+':case '-':case '*':case '/':
        case ';':case '(':case ')':case '=':
            return curr_tok = Token_value(ch);

        //这些需要串成一个完整的浮点数
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            cin.putback(ch);
            cin>>number_value;
            return curr_tok = NUMBER;

        default:
            //输入字母时，串成一整个变量名
            if (isalpha(ch)) {
                string_value = ch;
                while(cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
                cin.putback(ch);
                return curr_tok = NAME;
            }

            //既不是字母也不是数字，也不是运算符，报错
            error("bad token");
            return curr_tok = PRINT;
    }
}

int no_of_errors;//统计语句中错误个数
double error(const string& s) {
    no_of_errors ++;
    cerr<<"error: "<<s<<'\n';//预定好的输出字符串，如"bad token"
    return 1;
}
int main()
{
    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;

    while(cin) {
        get_token();
        if(curr_tok == END) break;
        if(curr_tok == PRINT) continue;
        cout<<expr(false)<<'\n';
    }
    return no_of_errors;
}
