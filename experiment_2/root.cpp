//
// Created by lyc on 2024/4/22.
//


//原本定义了Root类和User类，但是发现不如用txt直接存储，存储长久，且方便操作
#include"iostream"
#include"string"
using namespace std;
class root{
    root(string name,string password){
        this->m_name = name;
        this->m_password = password;
    }
private:
    string m_name;
    string m_password;
public:
    void get_rootName();
    void get_rootPassword();
};

void root::get_rootName() {
    cout<<"管理员名称:"<<m_name<<endl;
}
void root::get_rootPassword() {
    cout<<"管理员密码:"<<m_password<<endl;
}