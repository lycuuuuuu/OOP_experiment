//
// Created by lyc on 2024/5/26.
//


//这是个用于测试的文件，请忽略

#include"iostream"
#include"time.h"
#include"fstream"
using namespace std;
int main(){
//    time_t now;
//    time(&now);
//
//    struct tm* timeinfo;
//    timeinfo = localtime(&now);
//    char buffer[80];
//    strftime(buffer,80,"%Y-%m-%d %H:%M:%S",timeinfo);
//
//    cout<<buffer<<endl;

    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    string line;
    getline(file,line);
    cout<<line<<endl;
    file.close();
    fstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)",ios::app);
    newfile<<"newline"<<endl;
    string word = "world";
    string newline = "hello"+word+"\n";
    newfile<<newline;
    newfile<<"wow"<<endl;
    newfile.close();
    return 0;
}