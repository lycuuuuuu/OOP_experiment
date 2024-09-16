//
// Created by lyc on 2024/4/22.
//
#include"DeskTop_Calculator_OOP.cpp"
int main(){
    get_token g;
    expr ex;
    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;
    while(cin) {
        g.getToken();
        if(curr_tok == END) break;
        if(curr_tok == PRINT) continue;
        cout<<ex.PlusOrMinus(false)<<'\n';
    }
    return no_of_errors;

}