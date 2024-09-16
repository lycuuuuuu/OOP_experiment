//
// Created by lyc on 2024/5/5.
//


//除了提供几个函数接口外，还做到了连接几个涉及商品信息操作的文件
#pragma once
#include"product.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_2\management.cpp"


class ProductManagement{
private:
    string m_name;  //目标商品名称
public:
    ProductManagement(string pname){
        this->m_name = pname;
    }

    //查找是否存在这个商品
    int findProduct();

    //打印商城信息（即打印所有售卖的商品信息）
    void printProduct();
};




int ProductManagement::findProduct() {

    //通过对txt的读操作，来查询是否存在该商品
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    if(!file){
        cerr<<"Unable to open file!"<<endl;
        EXIT_FAILURE;
        //打开文件失败———报错，退出
    }
    string line;
    string line_name;
    while(getline(file,line)){
            if(line=="Product"){
                getline(file,line_name);
                if(line_name=="name:  "+m_name){
                    //存在，返回true
                    return true;
                }
            }
    }

    //读不到，即不存在，返回false
    return false;
}

//打印商城信息，很简答，把product.txt的内容顺着打印一遍即可
void ProductManagement::printProduct() {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    string line;
    while(getline(file,line)){
        cout<<line<<endl;
    }
}

