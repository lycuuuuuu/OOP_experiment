//
// Created by lyc on 2024/4/21.
//
#include"iostream"
using namespace std;
istream *input;
int main(){

    cout<<"input="<<input<<endl;
    input = &cin;
    cout<<input<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}
