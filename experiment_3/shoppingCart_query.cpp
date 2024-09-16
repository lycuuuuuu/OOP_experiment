//
// Created by lyc on 2024/5/5.
//


//查询购物车信息，就是把该用户的购物车打印一遍
#pragma once
#include"ProductManagement.cpp"
#include"searchProduct.cpp"


class shoppingCart_query{
private:
    vector<string>products; //一个容器，下方解释
public:
    bool cart_query();      //查询（打印）整个购物车


    void cart_product_query();  //查询某个（或某些）商品的信息
    //下方四个函数都是辅助cart_product_query的
    double getPrice(string name);
    double getPrice(int number);    //两个getPrice函数传参不同，实现的功能不同，下方会讲解
    int getNumber(int number);
    int getNumberFromCart(string s);    //两个getNumber函数也是功能不同
};

void shoppingCart_query::cart_product_query() {
    //人机交互界面会给出购物车中的所有商品（按照一定编号顺序），但是每个商品只有名称和购买数量两个信息
    //此时用户想要查询哪个商品的具体信息（名称，单价，描述，库存），就输入相应的编号即可，可以一次性输入多个（123），此函数会依次查询1、2、3
    //号商品的信息
    cout<<"请输入要查询的商品对应编号"<<endl;
    int num;
    cin>>num;
    string pname = products[num-1];
    searchProduct S(pname);
    S.searchP();
    //searchP:去product.txt中寻找商品的信息，并打印出来
}


double shoppingCart_query::getPrice(string name) {

    //去txt文件中读出商品的价格（通过商品名称检索）
    string p_name = "name:  "+name;
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    string line,line1;
    while(getline(file,line)){
        if(line==p_name)getline(file,line1);
    }
    string price_string;
    for(int i=7;i<line1.length();i++){
        price_string.push_back(line1[i]);
    }
    double price = stod(price_string);
    file.close();
    return price;
}


double shoppingCart_query::getPrice(int number) {
    //为编号为number的商品查询价格
    string name = products[number-1];
    double price = getPrice(name);
    return price;
}

//把输入的数字串（比如1234），拆分为一个一个的数字（1、2、3、4），用于查询商品的具体信息
int shoppingCart_query::getNumber(int number){
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    string line,number_string;
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME) {
//            cout<<line<<endl;
//            cout<<number<<endl;
            for (int i = 0; i <= 2 * (number); i++) {
                getline(file, line);
            }
//            cout<<line<<endl;

            for (int j = 7; j < line.length(); j++) {
                number_string.push_back(line[j]);
            }
//            cout << "stoi前没问题" << endl;
//            cout << number_string << endl;
            return stoi(number_string);
        }
    }
}


//获得该商品在购物车中的数量
int shoppingCart_query::getNumberFromCart(string s) {
    string number_string;
    int number;
    for(int i=7;i<s.length();i++){
        number_string.push_back(s[i]);
    }
    return stoi(number_string);
}


//查询购物车，打印购物车信息，并且为每个商品计算总价
bool shoppingCart_query::cart_query() {
    if(LOGIN_STATE==UNLOGIN){
        //未登录状态是查不到购物车的
        cerr<<"尚未登录!"<<endl;
        return false;
    }

    //通过对txt文件的读操作查询，并用容器记录信息
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    string line,line1;
    vector<string>lines;
//    vector<string>products;
    double totalPrice;
    int isFindCart = 0;
    int num=0;
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME){
            isFindCart = 1;
            getline(file,line);
            getline(file,line);
            while(line!="end"){
                num++;
                cout<<num<<". "<<line<<"   ";
                getline(file,line1);
                cout<<line1<<"   ";
                //输出商品单价
                cout<<"single price:"<<getPrice(line)<<"    ";
                //输出商品总价
                cout<<"total price:"<<getPrice(line)* getNumberFromCart(line1)<<endl;

                totalPrice = totalPrice + getPrice(line)* getNumberFromCart(line1);
                products.push_back(line);
                getline(file,line);
            }
        }
    }

    if(isFindCart==0){
        //没有创建购物车
        cerr<<"未找到购物车，请先创建!"<<endl;
        return false;
    }
    if(num==0){
        //购物车中还没有商品
        cerr<<"购物车内还没有商品，先去逛一逛吧!"<<endl;
        return false;
    }

    cout<<"Total Price:"<<totalPrice<<endl;//购物车所有商品价格总和
    file.close();
    cout<<"是否要查询其中商品的详细信息?(回答“1(是)”或“0(否)”)"<<endl;
    string IsOrNot;
    cin>>IsOrNot;
    if(IsOrNot=="1"){
        cart_product_query();
    }
    return true;
}
