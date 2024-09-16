//
// Created by lyc on 2024/4/22.
//
#include"DeskTop_Calculator_Module.cpp"
int main(){
    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;
    while(cin){
        get_token::get_token();
        if(curr_tok==END)break;
        if(curr_tok==PRINT)continue;
        cout<<expr::PlusOrMinus(false)<<'\n';
    }
    return no_of_errors;
}