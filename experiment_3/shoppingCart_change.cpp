//
// Created by lyc on 2024/5/5.
//


//�޸Ĺ��ﳵ����Ʒ��Ϣ��һ����Ǹ�������
#include"ProductManagement.cpp"

class shoppingCart_change{
private:
    string cc_name;     //���޸���Ʒ������
    int cc_aimPurchaseNumber;   //�޸ĺ����Ŀ
public:
    shoppingCart_change(string name,int aimPurchaseNumber){
        this->cc_name = name;
        this->cc_aimPurchaseNumber = aimPurchaseNumber;
    }

    //�޸���Ϣ
    void cart_change();
};




void shoppingCart_change::cart_change() {
    //ͨ����txt�ļ��Ķ�д����ʵ��
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    string line;
    vector<string>lines;

    //symbol����
    //symbol_user����־λ����ʾ�û��Ƿ񴴽��˹��ﳵ
    //symbol_product����־λ����ʾ���ﳵ���Ƿ��и���Ʒ
    int symbol=0,symbol_user=0,symbol_product=0;

    while(getline(file,line)){
        //���ҵ���ǰ�û�����λ��
        if(line=="User: "+CURRENT_LOGIN_NAME){
            symbol_user=1;
            symbol=1;
        }
        //��ʼ����Ʒ����λ�ã����޸�����
        if(line==cc_name&&symbol==1){
            symbol_product=1;
            lines.push_back(line);
            getline(file,line);
            line = "number:" + to_string(cc_aimPurchaseNumber);
        }
        lines.push_back(line);
    }
    if(symbol_user==0){
        cerr<<"���û���δ�������ﳵ!"<<endl;
        return;
    }
    if(symbol_product==0){
        cerr<<"����Ʒ��δ���빺�ﳵ!"<<endl;
        return;
    }
    file.close();

    //�޸ĺ�д��
    ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    for (string newLine: lines) {
        newfile << newLine << endl;
    }
    newfile.close();
    cout<<"�޸ĳɹ���"<<endl;
}