//
// Created by lyc on 2024/5/6.
//


//这是个测试文件，不用理会
#include"iostream"
#include"string"
#include"fstream"
using namespace std;
double getPrice(string name) {
//    string p_name = "name:  "+name;
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    string line,line1;
    while(getline(file,line)){
        if(line==name)getline(file,line1);
    }
    string price_string;
    for(int i=7;i<line1.length();i++){
        price_string.push_back(line1[i]);
    }
    double price = stod(price_string);
    file.close();
//    cout<<price_string<<endl;
    return price;
}

int main(){
    cout<<getPrice("name:  iPhone19")<<endl;
    cout<<getPrice("name:  华为Pura7")<<endl;
    /*string string1;
    string string2;
    string string3 = "iPhone18";
    string string1plus2;
    string1 = "name:  ";
    string2 = string3;
    string1plus2 = string1+string2;
    cout<<string1plus2;
    */
//    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
//    string line1,line2,line3;
//    getline(file,line1);
//    cout<<line1<<endl;
//    getline(file,line2);
//    cout<<line2<<endl;
//    getline(file,line3);
//    cout<<line3<<endl;
//    cout<<line1<<"/"<<line2<<"/"<<line3<<endl;
    return 0;
}

