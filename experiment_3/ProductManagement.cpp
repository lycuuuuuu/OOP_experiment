//
// Created by lyc on 2024/5/5.
//


//�����ṩ���������ӿ��⣬�����������Ӽ����漰��Ʒ��Ϣ�������ļ�
#pragma once
#include"product.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_2\management.cpp"


class ProductManagement{
private:
    string m_name;  //Ŀ����Ʒ����
public:
    ProductManagement(string pname){
        this->m_name = pname;
    }

    //�����Ƿ���������Ʒ
    int findProduct();

    //��ӡ�̳���Ϣ������ӡ������������Ʒ��Ϣ��
    void printProduct();
};




int ProductManagement::findProduct() {

    //ͨ����txt�Ķ�����������ѯ�Ƿ���ڸ���Ʒ
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    if(!file){
        cerr<<"Unable to open file!"<<endl;
        EXIT_FAILURE;
        //���ļ�ʧ�ܡ����������˳�
    }
    string line;
    string line_name;
    while(getline(file,line)){
            if(line=="Product"){
                getline(file,line_name);
                if(line_name=="name:  "+m_name){
                    //���ڣ�����true
                    return true;
                }
            }
    }

    //���������������ڣ�����false
    return false;
}

//��ӡ�̳���Ϣ���ܼ�𣬰�product.txt������˳�Ŵ�ӡһ�鼴��
void ProductManagement::printProduct() {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    string line;
    while(getline(file,line)){
        cout<<line<<endl;
    }
}

