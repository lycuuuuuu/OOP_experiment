//
// Created by lyc on 2024/4/29.
//
#include"management.cpp"


//�޸�����
class ChangePassword{
private:
    string c_account;   //�û��˺�
    string c_password;  //�û��޸ĺ������
public:
    ChangePassword(string account,string password){
        this->c_account = account;
        this->c_password = password;
    }

    void ChangeP(); //�޸�����

};


void ChangePassword::ChangeP() {
    //ͨ��txt�ļ���ȡ��������ȡ�û�����
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_2\User.txt)");
    if(!file){
        cerr<<"Unable to open file!"<<endl;
        EXIT_FAILURE;
        //���ļ�ʧ�ܡ��������˳�
    }
    string line;
    vector<string> lines;
    int symbol = 0;     //��־λ���ҵ���Ӧ�û��˺���1
    while(getline(file,line)){
        if(line==c_account)symbol=1;
        if(line=="password"&&symbol==1){
            lines.push_back(line);
            lines.push_back(c_password);    //�޸����룺ԭ��������ԭ����ʱ����������������У����ǰ��µ������������
            getline(file,line);
            getline(file,line);
            symbol=0;
        }

        lines.push_back(line);
    }
    file.close();

    //�������е�����д��txt�ļ�
    fstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_2\User.txt)");
    for(string newLine:lines){
        newfile<<newLine<<endl;
    }
    newfile.close();
    cout<<"���óɹ���"<<endl;
}