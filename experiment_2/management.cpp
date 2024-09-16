//
// Created by lyc on 2024/4/22.
//

//management�ļ�����Ҫ����Ȼ�漰���Ĺ��ܱȽ��٣����������Ӹ����ļ�����������������ﶨ����ڵ�¼״̬��ȫ�ֱ���
#include"string"
#define USER 0
#define ROOT 1
#define UNLOGIN 2
int LOGIN_STATE = UNLOGIN;
std::string CURRENT_LOGIN_NAME = "UNLOGIN";

//������ȫ�ֱ���LOGIN_STATE(��ʾ��ǰ��¼״̬��USER/ROOT/UNLOGIN��δ��¼��)
//CURRENT_LOGIN_NAME����ʾ��ǰ��¼�˺ţ�
//----------------------------------------------------------------------------

#pragma  once
#include"fstream"
#include"vector"
#include"iostream"
using namespace std;


class management{
public:
    //������������Ҫ���ڵ�¼
    int findUser(string account,string password);
    int findRoot(string account,string password);
    //�����������û�ã����ǲ���óȻɾ��
    bool judgeState();
};


int management::findUser(string account,string password) {
    string a_or_p="else";   //��־λ����ʾ��ǰ���ں˶��˺Ż�������
    int result_a=0; //��־λ�������˺źͿ����˺�һ�£���1
    int result_p=0; //��־λ������������ȷ����1

    //ͨ��txt�ļ����ж�ȡ�����˶��˺ţ��˺���ȷ���ٺ˶Ը��˺���Ӧ����
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_2\User.txt)");
    if(!file){
        cerr<<"Unable to open file!"<<endl;
        EXIT_FAILURE;
        //���ļ�ʧ�ܡ��������˳�
    }

    string line;
    while(getline(file,line)){
        if(a_or_p=="account"){
            //�˶��˺�
            if(line==account)result_a=1;
        }

        //������"account"�ؼ��֣��ҵ�ǰ��־λΪelse��������Ϊaccount,��ʾ������Ҫ�˶��ʺ���
        if(line=="account"&&a_or_p=="else") a_or_p = "account";


        if(a_or_p=="password"){
            //�˶�����
            if(line==password&&result_a==1) result_p=1; //������ȷ
            if(result_a == 1 && result_p == 1) return 2;    //�˺����붼��ȷ������2
            if(result_a == 1 && result_p != 1) return 1;    //�˺���ȷ�����벻��ȷ������1
            //����������ʵ�Ƕ���ģ����Ǵ������ܾͲ�Ҫ�ģ�����ұ�����
            a_or_p="else";
            result_a=0;
            result_p=0;
        }

        //�պ˶����˺ţ��ɹ������Ҷ����ؼ���"password"���������Ҫ�˶�����
        if(line=="password"&&a_or_p=="account") a_or_p="password";

    }
    file.close();
    return 0;   //�������˺ţ���û�к˶�����ı�Ҫ��ֱ�ӷ���0
}



int management::findRoot(string account,string password) {
    //�˶Թ���Ա���˺����룬���Ϸ���findUserͬ����������
    string a_or_p="else";
    int result_a=0;
    int result_p=0;
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_2\Root.txt)");
    if(!file){
        cerr<<"Unable to open file!"<<endl;
        EXIT_FAILURE;
    }
    string line;
    while(getline(file,line)){
        if(a_or_p=="account"){
            if(line==account)result_a=1;
        }

        if(line=="account"&&a_or_p=="else") a_or_p = "account";

        if(a_or_p=="password"){
            if(line==password&&result_a==1) result_p=1;
            if(result_a == 1 && result_p == 1) return 2;
            if(result_a == 1 && result_p != 1) return 1;
            a_or_p="else";
            result_a=0;
            result_p=0;
        }

        if(line=="password"&&a_or_p=="account") a_or_p="password";

    }
    file.close();
    return 0;
}

bool management::judgeState() {
//û��
}

