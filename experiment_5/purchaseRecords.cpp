//
// Created by lyc on 2024/5/26.
//


//这个类用来生成和查询（打印）用户购买记录
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\ProductManagement.cpp"

class purchaseRecords{
private:
    int choice_number;          //购买的商品的序号
    int purchase_number;        //购买数量
public:
    purchaseRecords(int cn=0,int pn=0){
        choice_number = cn;
        purchase_number = pn;
    }

    void addRecord();       //增加购买记录
    void queryRecords();    //查询（打印）购买记录
};


//增加购买记录，和购买商品的功能配套使用
void purchaseRecords::addRecord() {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    string line,product;
    bool findUser=false;        //首先看购买记录库中是否已经存在用户的购买记录，有的话，直接在后面添加即可
                                //没有的话，创建新的用户结构（固定格式）
                                //这个作为标志位

    //根据商品序号，去购物车中查询商品名称
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME){
            getline(file,line);
            getline(file,product);
            for(int i=1;i<choice_number;i++){
                getline(file,line);
                getline(file,product);
            }
        }
    }
    file.close();


go:
    //通过文本写操作，为用户添加新的购买记录，包括购买商品名称、数量、时间
    fstream anotherFile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_5\purchaseRecords.txt)");
    string newline;
    vector<string>lines;
    while(getline(anotherFile,newline)){
        if(newline=="User: "+CURRENT_LOGIN_NAME){
            lines.push_back(newline);
            findUser=true;
//            anotherFile<<line<<endl<<"number:"<<purchase_number<<endl<<"time:";

            lines.push_back(product);
            line ="number:"+ to_string(purchase_number);
            lines.push_back(line);

            //这里是获取当前系统的时间
            time_t now;
            time(&now);
            struct tm* timeinfo;
            timeinfo = localtime(&now);
            char buffer[80];
            strftime(buffer,80,"%Y-%m-%d-%H:%M:%S",timeinfo);       //时间按照年-月-日-时-分-秒的格式
//            anotherFile<<buffer<<endl
            lines.push_back(buffer);
            getline(anotherFile,newline);
        }
        lines.push_back(newline);
    }
    anotherFile.close();

    //把添加的内容写进文本文件
    fstream addRecords(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_5\purchaseRecords.txt)");
    for(string newLine:lines){
        addRecords<<newLine<<endl;
    }
    addRecords.close();


    //如果用户之前没有购买记录（即没有相应的用户结构），则创建新的，并加入此次购买记录
    if(findUser==false){
        fstream newFile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_5\purchaseRecords.txt)",ios::app);
        newFile<<"User: "+CURRENT_LOGIN_NAME<<endl<<"end"<<endl;
        newFile.close();
        goto go;    //跳转回去添加购买记录
    }
}

//打印当前用户的所有购买记录
void purchaseRecords::queryRecords() {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_5\purchaseRecords.txt)");
    string line;
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME){
            cout<<line<<endl;
            while(line!="end"){
                getline(file,line);
                cout<<line<<endl;
            }
        }
    }
    file.close();
}


//测试用，请忽略

//int main(){
//    CURRENT_LOGIN_NAME = "2203051";
//    purchaseRecords PR(1,5);
//    PR.addRecord();
//    PR.queryRecords();
//    return 0;
//}