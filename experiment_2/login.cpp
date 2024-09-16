//
// Created by lyc on 2024/4/22.
//
#include"management.cpp"


//登录
class login{
private:
    string l_account;   //账号
    string l_password;  //密码
public:
    login(string account,string password){
        this->l_account = account;
        this->l_password = password;
    }

    void loginUser();   //用户登录
    void loginRoot();   //管理员登录
};

void login::loginUser(){
    management M;
    //management类，主要提供提供findUser(),findRoot()接口
    // 作用是比较输入的账号和密码与库中账号密码是否相同
    //账号密码都不对返回0，账号对密码不对返回1，都对返回2
    if (M.findUser(l_account,l_password) == 2) {
        cout << "账号和密码正确，登录成功！" << endl;

        //management文件中，设置了全局变量LOGIN_STATE(表示当前登录状态)
        //CURRENT_LOGIN_NAME（表示当前登录账号）
        LOGIN_STATE = USER;
        CURRENT_LOGIN_NAME = l_account;
    }
    else {
        //虽然findUser对失败进行的区分（对一个或者都不对），但是为了安全起见，不会向用户展示细节
        cout << "账号或密码有误，登陆失败！" << endl;
    }
}

//管理员登录，和用户登录同理
void login::loginRoot(){
    management M;
    if (M.findRoot(l_account, l_password) == 2) {
        cout << "账号和密码正确，登录成功！" << endl;
        LOGIN_STATE = ROOT;
        CURRENT_LOGIN_NAME = l_account;
    } else {
        cout << "账号或密码有误，登陆失败！" << endl;
    }
}

