//
// Created by lyc on 2024/5/5.
//


//ɾ�����ﳵ�е���Ʒ
#include"ProductManagement.cpp"

class shoppingCart_delete{
private:
    string cd_name;     //��ɾ��Ʒ������
public:
    shoppingCart_delete(string name){
        this->cd_name = name;
    }

    //ɾ��
    void cart_delete();
};




void shoppingCart_delete::cart_delete() {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    string line/*,line1*/;
    vector<string>lines;
    int symbol=0;   //û��
    int isFind = 0; //��־λ���жϹ��ﳵ���Ƿ���ڸ���Ʒ
//    while(getline(file,line)){
//        if(line=="Cart"){
//            getline(file,line1);
//            if(line1=="User: "+cd_name){
//                while(line!="Cart"){
//                    getline(file,line1);
//                }
//            }
//        }
//        lines.push_back(line);
//    }

//��д�ļ�
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME)symbol=1;
        if(line==cd_name){
            isFind =  1;
            //����ҵ��˸���Ʒ��ֱ�Ӻ���������Ϣ���ֱ��Ӧ���ƺ����������Ӷ�ɾ��
            getline(file,line);
            getline(file,line);
        }
        symbol=0;
        lines.push_back(line);
    }
    if(isFind==0){
        cerr<<"��Ʒ������!"<<endl;
        return;
    }
    file.close();

    //���޸ĺ����Ϣд���ļ�
    ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    for(string newLine:lines){
        newfile<<newLine<<endl;
    }
    newfile.close();
    cout<<"ɾ���ɹ���"<<endl;
}