//
// Created by lyc on 2024/4/29.
//
#include"management.cpp"


//�û�ע��
class Register{
private:
    string r_account;   //�û���Ҫ���˺�
    string r_password;  //�û���Ҫ������
public:
    Register(string account,string password){
        this->r_account = account;
        this->r_password  = password;
    }

    //ע��
    int  RegisterUser();

};



int  Register::RegisterUser() {
    management M;

    //findUser����1��2������ʾ�������и��˺�
    if (M.findUser(r_account,r_password) != 0) {
        cout << "�˺��ѱ�ע��" << endl;
        return 1;
    }

    //"password"��txt�ļ������ڼ������Ĺؼ��֣���������ȡ�����������
    if(r_password=="password"){
        cout<<"�벻Ҫ����Ϊ��password��,������"<<endl;
        return 2;
    }

    //��txt�ļ�����д������ֱ����ĩβ���ո�ʽ�����µ��˺�����
    ofstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_2\User.txt)",ios::app);
    if(!file){
        cerr<<"Unable to open file!";
        EXIT_FAILURE;
        //���ļ�ʧ�ܡ�����������
    }
    file<<""<<endl;
    file<<"account"<<endl;
    file<<r_account<<endl;
    file<<"password"<<endl;
    file<<r_password<<endl;
    cout<<"ע��ɹ���"<<endl;
    file.close();
    return 0;
}