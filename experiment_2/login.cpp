//
// Created by lyc on 2024/4/22.
//
#include"management.cpp"


//��¼
class login{
private:
    string l_account;   //�˺�
    string l_password;  //����
public:
    login(string account,string password){
        this->l_account = account;
        this->l_password = password;
    }

    void loginUser();   //�û���¼
    void loginRoot();   //����Ա��¼
};

void login::loginUser(){
    management M;
    //management�࣬��Ҫ�ṩ�ṩfindUser(),findRoot()�ӿ�
    // �����ǱȽ�������˺ź�����������˺������Ƿ���ͬ
    //�˺����붼���Է���0���˺Ŷ����벻�Է���1�����Է���2
    if (M.findUser(l_account,l_password) == 2) {
        cout << "�˺ź�������ȷ����¼�ɹ���" << endl;

        //management�ļ��У�������ȫ�ֱ���LOGIN_STATE(��ʾ��ǰ��¼״̬)
        //CURRENT_LOGIN_NAME����ʾ��ǰ��¼�˺ţ�
        LOGIN_STATE = USER;
        CURRENT_LOGIN_NAME = l_account;
    }
    else {
        //��ȻfindUser��ʧ�ܽ��е����֣���һ�����߶����ԣ�������Ϊ�˰�ȫ������������û�չʾϸ��
        cout << "�˺Ż��������󣬵�½ʧ�ܣ�" << endl;
    }
}

//����Ա��¼�����û���¼ͬ��
void login::loginRoot(){
    management M;
    if (M.findRoot(l_account, l_password) == 2) {
        cout << "�˺ź�������ȷ����¼�ɹ���" << endl;
        LOGIN_STATE = ROOT;
        CURRENT_LOGIN_NAME = l_account;
    } else {
        cout << "�˺Ż��������󣬵�½ʧ�ܣ�" << endl;
    }
}

