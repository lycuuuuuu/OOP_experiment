//
// Created by lyc on 2024/5/5.
//

//�������ﳵ
#include"ProductManagement.cpp"

class shoppingCart_create{
private:
    string m_Username;      //�û�����
public:
    shoppingCart_create(string Username){
        this->m_Username = Username;
    }

    //�жϸ��û��Ĺ��ﳵ�Ƿ����
    bool isCartExist();

    //�������ھͿ��Դ���
    void cart_create();
};




bool shoppingCart_create::isCartExist() {

    //ͨ���򵥵�txt�ļ�������ʵ��
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    string line;
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME){
            cerr<<"���ﳵ�Ѵ���!"<<endl;
            return false;
        }

    }
    return true;
}



void shoppingCart_create::cart_create() {
    if(isCartExist()==false){
        return;
    }


    //��txt�ļ���д������֮�����ļ�ĩβ������Ϣ
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)",ios::app);
    file<<"Cart"<<endl;
    file<<"User: "<<m_Username<<endl;
    file<<"Product"<<endl;
    file<<"end"<<endl;
    file<<endl;
}