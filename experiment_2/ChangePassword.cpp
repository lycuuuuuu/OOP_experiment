//
// Created by lyc on 2024/4/29.
//
#include"management.cpp"


//修改密码
class ChangePassword{
private:
    string c_account;   //用户账号
    string c_password;  //用户修改后的密码
public:
    ChangePassword(string account,string password){
        this->c_account = account;
        this->c_password = password;
    }

    void ChangeP(); //修改密码

};


void ChangePassword::ChangeP() {
    //通过txt文件读取操作，读取用户密码
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_2\User.txt)");
    if(!file){
        cerr<<"Unable to open file!"<<endl;
        EXIT_FAILURE;
        //打开文件失败——报错，退出
    }
    string line;
    vector<string> lines;
    int symbol = 0;     //标志位，找到相应用户账号置1
    while(getline(file,line)){
        if(line==c_account)symbol=1;
        if(line=="password"&&symbol==1){
            lines.push_back(line);
            lines.push_back(c_password);    //修改密码：原理，当读到原密码时，不将其放入容器中，而是把新的密码放入容器
            getline(file,line);
            getline(file,line);
            symbol=0;
        }

        lines.push_back(line);
    }
    file.close();

    //将容器中的内容写回txt文件
    fstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_2\User.txt)");
    for(string newLine:lines){
        newfile<<newLine<<endl;
    }
    newfile.close();
    cout<<"设置成功！"<<endl;
}