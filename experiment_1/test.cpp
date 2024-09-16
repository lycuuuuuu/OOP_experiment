//
// Created by lyc on 2024/4/21.
//
#include"iostream"
using namespace std;
int main(int argc,char* argv[]){
    cout<<argc<<endl;
    cout<<argv[1]<<endl;
    char ch;
    if(cin.get(ch))cout<<ch<<endl;
    if(isspace(ch))cout<<"isSpace"<<endl;
    if(ch = '\n')cout<<"isEnter"<<endl;
    if(!cin.get(ch)) cout<<"error"<<endl;
    return 0;
}
