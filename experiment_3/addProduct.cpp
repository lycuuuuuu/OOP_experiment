//
// Created by lyc on 2024/5/5.
//


//管理员添加商品
#include"ProductManagement.cpp"
class addProduct{
private:
    string a_name;      //名称
    double a_price;     //单价
    string a_detail;    //描述
    int a_stock;        //库存
public:
    addProduct(string name,double price,string detail,int stock){
        this->a_name = name;
        this->a_price = price;
        this->a_detail = detail;
        this->a_stock = stock;
    }

    //添加商品
    void addP();
};

void addProduct::addP() {

    //通过对txt文件进行写操作来添加
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)",ios::app);
    if(!file){
        cerr<<"Unable to open file";
        EXIT_FAILURE;
        //打开文件失败——报错，返回
    }

    //严格按照设定好的格式加在文件末尾
    file<<"Product"<<endl;
    file<<"name:  "<<a_name<<endl;
    file<<"price: "<<a_price<<endl;
    file<<"detail:"<<a_detail<<endl;
    file<<"stock: "<<a_stock<<endl;
    file<<endl;
    cout<<"添加商品成功！"<<endl;
    file.close();
}