//
// Created by lyc on 2024/5/5.
//

//创建购物车
#include"ProductManagement.cpp"

class shoppingCart_create{
private:
    string m_Username;      //用户名称
public:
    shoppingCart_create(string Username){
        this->m_Username = Username;
    }

    //判断该用户的购物车是否存在
    bool isCartExist();

    //若不存在就可以创建
    void cart_create();
};




bool shoppingCart_create::isCartExist() {

    //通过简单的txt文件读操作实现
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    string line;
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME){
            cerr<<"购物车已存在!"<<endl;
            return false;
        }

    }
    return true;
}



void shoppingCart_create::cart_create() {
    if(isCartExist()==false){
        return;
    }


    //对txt文件的写操作，之间在文件末尾加上信息
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)",ios::app);
    file<<"Cart"<<endl;
    file<<"User: "<<m_Username<<endl;
    file<<"Product"<<endl;
    file<<"end"<<endl;
    file<<endl;
}