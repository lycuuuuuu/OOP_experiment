//
// Created by lyc on 2024/4/22.
//


//原本定义了Root类和User类，但是发现不如用txt直接存储，存储长久，且方便操作
#include"string"
#include"iostream"
using namespace std;
class user{
    user(string name,string password){
        this->m_name = name;
        this->m_password = password;
    }
private:
    string m_name;
    string m_password;
public:
    void get_userName();
    void get_userPassword();
};

void user::get_userName() {
    cout<<"用户名:"<<m_name<<endl;
}

void user::get_userPassword() {
    cout<<"用户密码:"<<m_password<<endl;
}