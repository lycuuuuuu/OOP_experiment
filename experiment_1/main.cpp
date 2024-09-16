
#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;

// 将token用他们的字符所对应的整数表示，这样做既方便有效，
// 又能帮助使用排错系统的人。
enum Token_value {
    NAME, NUMBER, END, PLUS='+',
    MINUS='-', MUL='*', DIV='/',
    PRINT=';', ASSIGN='=', LP='(', RP=')',
};
//最后一次调用get_token（）的值可以在curr_tok中找到
Token_value curr_tok = PRINT;
// 每个分析器都有一个bool参数
double expr(bool);//处理加减
double term(bool);
double prim(bool);
Token_value get_token();
double error(const string&);
map<string, double> table;

// 指明该函数是否需要调用get_token()去取得下一个参数
// expr处理加减，一直到不是加减返回left
double expr(bool get) {
    double left = term(get);
    for(;;) {
        switch (curr_tok){
        case PLUS:
            left += term(true);
            break;
        case MINUS:
            left -= term(true);
            break;
        default:
            return left;
        }
    }
}

// 函数term处理乘除，采用的方式与expr()处理方法一样
double term(bool get) {
    double left = prim(get);
    for(;;) {
        switch (curr_tok){
        case MUL:
            left *= prim(true);
            break;
        case DIV:
            if (double d = prim(true)) {
                left /= d;
                break;
            }
            return error("divide by 0");
        default:
            return left;
        }
    }
}
//使调用层次进入更下一层，且不用做循环
double number_value;
string string_value;

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
    case MINUS:            //一元
        return -prim(true);
    case LP: {                //吃掉‘）’
        double e = expr(true);
        if (curr_tok != RP) return error(" ) expected");
        get_token();
        return e;
    }
    default:
        return error("primary expected");
    }
}

Token_value get_token() {
    char ch;

    do { // 低级输入，改进输入
        if(!cin.get(ch)) return curr_tok = END;
    } while(ch != '\n' && isspace(ch));

    switch(ch) {
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
        error("bad token");
        return curr_tok = PRINT;
    }
}
int no_of_errors;
double error(const string& s) {
    no_of_errors ++;
    cerr<<"error: "<<s<<'\n';
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
