//
// Created by lyc on 2024/4/22.
//

//management文件很重要，虽然涉及到的功能比较少，但它是连接各个文件的桥梁，因此在这里定义关于登录状态的全局变量
#include"string"
#define USER 0
#define ROOT 1
#define UNLOGIN 2
int LOGIN_STATE = UNLOGIN;
std::string CURRENT_LOGIN_NAME = "UNLOGIN";

//设置了全局变量LOGIN_STATE(表示当前登录状态：USER/ROOT/UNLOGIN（未登录）)
//CURRENT_LOGIN_NAME（表示当前登录账号）
//----------------------------------------------------------------------------

#pragma  once
#include"fstream"
#include"vector"
#include"iostream"
using namespace std;


class management{
public:
    //这两个函数主要用于登录
    int findUser(string account,string password);
    int findRoot(string account,string password);
    //这个函数疑似没用，但是不敢贸然删除
    bool judgeState();
};


int management::findUser(string account,string password) {
    string a_or_p="else";   //标志位：表示当前正在核对账号还是密码
    int result_a=0; //标志位，输入账号和库中账号一致：置1
    int result_p=0; //标志位：输入密码正确：置1

    //通过txt文件逐行读取，来核对账号，账号正确后，再核对该账号相应密码
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_2\User.txt)");
    if(!file){
        cerr<<"Unable to open file!"<<endl;
        EXIT_FAILURE;
        //打开文件失败——报错并退出
    }

    string line;
    while(getline(file,line)){
        if(a_or_p=="account"){
            //核对账号
            if(line==account)result_a=1;
        }

        //当读到"account"关键字，且当前标志位为else，将其置为account,表示接下来要核对帐号了
        if(line=="account"&&a_or_p=="else") a_or_p = "account";


        if(a_or_p=="password"){
            //核对密码
            if(line==password&&result_a==1) result_p=1; //密码正确
            if(result_a == 1 && result_p == 1) return 2;    //账号密码都正确：返回2
            if(result_a == 1 && result_p != 1) return 1;    //账号正确而密码不正确，返回1
            //下面三步其实是多余的，但是代码能跑就不要改，因此我保留了
            a_or_p="else";
            result_a=0;
            result_p=0;
        }

        //刚核对完账号（成功），且读到关键字"password"，则接下来要核对密码
        if(line=="password"&&a_or_p=="account") a_or_p="password";

    }
    file.close();
    return 0;   //不存在账号，则没有核对密码的必要，直接返回0
}



int management::findRoot(string account,string password) {
    //核对管理员的账号密码，和上方的findUser同理，不做讲解
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
//没用
}

