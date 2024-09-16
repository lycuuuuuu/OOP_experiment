//
// Created by lyc on 2024/4/29.
//
#include"management.cpp"


//用户注册
class Register{
private:
    string r_account;   //用户想要的账号
    string r_password;  //用户想要的密码
public:
    Register(string account,string password){
        this->r_account = account;
        this->r_password  = password;
    }

    //注册
    int  RegisterUser();

};



int  Register::RegisterUser() {
    management M;

    //findUser返回1或2，都表示库中已有该账号
    if (M.findUser(r_account,r_password) != 0) {
        cout << "账号已被注册" << endl;
        return 1;
    }

    //"password"是txt文件中用于检测密码的关键字，不能随意取，否则会乱套
    if(r_password=="password"){
        cout<<"请不要设置为“password”,请重试"<<endl;
        return 2;
    }

    //对txt文件进行写操作，直接再末尾按照格式加入新的账号密码
    ofstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_2\User.txt)",ios::app);
    if(!file){
        cerr<<"Unable to open file!";
        EXIT_FAILURE;
        //打开文件失败——报错，返回
    }
    file<<""<<endl;
    file<<"account"<<endl;
    file<<r_account<<endl;
    file<<"password"<<endl;
    file<<r_password<<endl;
    cout<<"注册成功！"<<endl;
    file.close();
    return 0;
}