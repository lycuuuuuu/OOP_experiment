//
// Created by lyc on 2024/5/5.
//


//����Ա�����Ʒ
#include"ProductManagement.cpp"
class addProduct{
private:
    string a_name;      //����
    double a_price;     //����
    string a_detail;    //����
    int a_stock;        //���
public:
    addProduct(string name,double price,string detail,int stock){
        this->a_name = name;
        this->a_price = price;
        this->a_detail = detail;
        this->a_stock = stock;
    }

    //�����Ʒ
    void addP();
};

void addProduct::addP() {

    //ͨ����txt�ļ�����д���������
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)",ios::app);
    if(!file){
        cerr<<"Unable to open file";
        EXIT_FAILURE;
        //���ļ�ʧ�ܡ�����������
    }

    //�ϸ����趨�õĸ�ʽ�����ļ�ĩβ
    file<<"Product"<<endl;
    file<<"name:  "<<a_name<<endl;
    file<<"price: "<<a_price<<endl;
    file<<"detail:"<<a_detail<<endl;
    file<<"stock: "<<a_stock<<endl;
    file<<endl;
    cout<<"�����Ʒ�ɹ���"<<endl;
    file.close();
}