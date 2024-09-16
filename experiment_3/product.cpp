//
// Created by lyc on 2024/5/5.
//


//商品类，和user/root一样，没用，之前觉得这个类可以提供查询商品信息的接口，方便后续的购买功能，但是发现还是没有直接对txt文件读写方便
#include"iostream"
#include"string"
using namespace std;
class product{
private:
    string m_name;  //名称
    double m_price; //单价
    string m_detail;//描述
    int m_stock;    //库存
public:
    product(string name,double price,string detail,int stock){
        this->m_name = name;
        this->m_price = price;
        this->m_detail = detail;
        this->m_stock = stock;
    }


    string getName();   //获取名称，基本没用，因为大部分时候是根据名称取查询其它信息
    string getPrice();  //获取价格
    string getDetail(); //获取描述
    string getStock();  //获取库存
};

string product::getName() {
    return m_name;
}
string product::getPrice() {
    string price = to_string(m_price);
    return price;
}
string product::getDetail() {
    return m_detail;
}
string product::getStock() {
    string stock = to_string(m_stock);
    return stock;
}
