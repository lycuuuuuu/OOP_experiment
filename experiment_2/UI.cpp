//
// Created by lyc on 2024/4/29.
//

//此文件主要用于人机交互界面，没技术含量

#include"login.cpp"
#include"register.cpp"
#include"ChangePassword.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\addProduct.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\deleteProduct.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\changeProduct.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\searchProduct.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart_create.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart_add.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart_query.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart_delete.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart_change.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_4\purchase.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_4\discount.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_5\dataAnalyze.cpp"


void showLogin_User(){
    string account_u;
    string password_u;
    cout << "请输入用户账号" << endl;
    cin >> account_u;
    cout << "请输入用户密码" << endl;
    cin >> password_u;
    login l1(account_u,password_u);
    l1.loginUser();
}
void showLogin_Root(){
    string account_r;
    string password_r;
    cout << "请输入管理员账号" << endl;
    cin >> account_r;
    cout << "请输入管理员密码" << endl;
    cin >> password_r;
    login l2(account_r,password_r);
    l2.loginRoot();
}


void showRegister(){
        string account_register;
        string password_register;
    Go_1:
        cout << "请设置账号" << endl;
        cin >> account_register;
    Go_2:
        cout << "请设置密码" << endl;
        cin>>password_register;
        Register R(account_register,password_register);
        int r = R.RegisterUser();
        if(r == 1)goto Go_1;
        if(r == 2)goto Go_2;
}

void showChangePassword(){
    string account,password;
    cout<<"请输入需要修改密码的账号"<<endl;
    cin>>account;
    cout<<"请设置新的密码"<<endl;
    cin>>password;
    ChangePassword C(account,password);
    C.ChangeP();
}

void showAddProduct(){
    ProductManagement pm("");
    pm.printProduct();
    cout<<"请输入要添加的商品"<<endl;
    string name,detail;
    double price;
    int stock;
    cout<<"商品名称"<<endl;
    cin>>name;
    cout<<"商品价格"<<endl;
    cin>>price;
    cout<<"商品描述"<<endl;
    cin>>detail;
    cout<<"商品库存"<<endl;
    cin>>stock;
    addProduct A(name,price,detail,stock);
    A.addP();
}

void showDeleteProduct(){
    ProductManagement pm("");
    pm.printProduct();
    cout<<"请输入要删除的商品的名称"<<endl;
    string name;
    cin>>name;
    deleteProduct D(name);
    D.deleteP();
}

void showChangeProduct(){
    ProductManagement pm("");
    pm.printProduct();
    cout<<"请输入待修改商品的名称"<<endl;
    string name,choice;
    string name_change;
    string detail_change;
    string price_change;
    string stock_change;
    cin>>name;
    changeProduct C(name);
    cout<<"请选择您想修改的内容(可多选)"
          "1.名称 2.价格 3.描述 4.库存"<<endl;
    cin>>choice;
    for (std::string::iterator it = choice.begin(); it != choice.end(); ++it) {
        if(*it=='1'){
            cout<<"修改名称\n请输入修改后的名称"<<endl;
            cin>>name_change;
            C.changeP(name_change,1);
        }
        if(*it=='2'){
            cout<<"修改价格\n请输入修改后的价格"<<endl;
            cin>>price_change;
            C.changeP(price_change,2);
        }
        if(*it=='3'){
            cout<<"修改描述\n请输入修改后的描述"<<endl;
            cin>>detail_change;
            C.changeP(detail_change,3);
        }
        if(*it=='4'){
            cout<<"修改库存\n请输入修改后的库存"<<endl;
            cin>>stock_change;
            C.changeP(stock_change,4);
        }
        /*else{
            cerr<<"输入错误!"<<endl;
            exit(0);
        }*/
    }
    cout<<"修改成功！"<<endl;
}

void showSearchProduct(){
    cout<<"请输入要查询商品的名称"<<endl;
    string name;
    cin>>name;
    searchProduct S(name);
    S.searchP();
}

void showCreateCart(){
    if(LOGIN_STATE==USER) {
        shoppingCart_create SCC(CURRENT_LOGIN_NAME);
        SCC.cart_create();
    }
    else if(LOGIN_STATE==ROOT){
        cerr<<"当前状态为管理员，请先切换到用户！"<<endl;
    }
    else if(LOGIN_STATE==UNLOGIN){
        cerr<<"尚未登录，请先登录！"<<endl;
    }
}

void showAddToCart(){
    if(LOGIN_STATE==UNLOGIN){
        cerr<<"尚未登录!"<<endl;
        return;
    }
    ProductManagement pm("");
    pm.printProduct();
    cout<<"请输入要加入购物车的商品名称"<<endl;
    string pname;
    cin>>pname;
    cout<<"请输入添加数量"<<endl;
    int number;
    cin>>number;
    if(LOGIN_STATE==USER) {
        shoppingCart_add SCA(pname,CURRENT_LOGIN_NAME,number);
        SCA.cart_add();
    }
    else if(LOGIN_STATE==ROOT){
        cerr<<"当前状态为管理员，请先切换到用户！"<<endl;
    }
    else if(LOGIN_STATE==UNLOGIN){
        cerr<<"尚未登录，请先登录！"<<endl;
    }

}

void showDeleteFromCart(){
    shoppingCart_query SCQ;
    int symbol=1;
    if(SCQ.cart_query()==false){
        return;
    }

    cout<<"请输入想要删除的商品名称"<<endl;
    string pname;
    cin>>pname;
    shoppingCart_delete SCD(pname);
    SCD.cart_delete();
}

void showChangeCartNum(){
    shoppingCart_query SCQ;
    if(SCQ.cart_query()==false){
        return;
    }
    cout<<"请输入要修改购买数目的商品名称"<<endl;
    string name;
    cin>>name;
    cout<<"请输入修改后的数目"<<endl;
    int aimNumber;
    cin>>aimNumber;
    shoppingCart_change SCC(name,aimNumber);
    SCC.cart_change();
}

void showPurchase(){
    purchase P;
    P.buyProduct();
}

void showDiscount(){
    if(LOGIN_STATE==UNLOGIN){
        cerr<<"请先登录!"<<endl;
        return;
    }
    cout<<"领取成功!"<<endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0,2);
    discount D;
    D.sendDiscount_random(dis(gen));
}

void showPrintProduct(){
    ProductManagement pm(" ");
    pm.printProduct();
}

void purchaseRecords_Query(){
    if(LOGIN_STATE==UNLOGIN){
        cerr<<"请先登录！"<<endl;
        return;
    }
    purchaseRecords PR;
    cout<<"购买记录如下："<<endl;
    PR.queryRecords();
}

void showDataAnalyze(){
    if(LOGIN_STATE==UNLOGIN){
        cerr<<"请先登录！"<<endl;
        return;
    }
    cout<<"顾客消费数据"<<endl;
    cout<<"请设置查询起始时间(格式 2024-01-01-00:00:00)"<<endl;
    string sTime;
    cin>>sTime;

    cout<<"情设置查询结束时间(格式 2024-01-01-00:00:00)"<<endl;
    string eTime;
    cin>>eTime;
    DataAnalyze DA(sTime,eTime);
    DA.Analyze();
}

void showMenu() {
    cout << "----------------------------" << endl;
    cout << "-----------登录系统-----------" << endl;
    cout << "---------(0)退出系统----------" <<endl;
    cout << "(1)用户登录              (2)管理员登录"  << endl;
    cout << "(3)用户注册              (4)用户修改密码" << endl;
    cout << "(5)添加商品              (6)删除商品"<<endl;
    cout << "(7)修改商品信息           (8)查询商品信息"<<endl;
    cout << "(9)创建购物车            (10)添加商品至购物车"<<endl;
    cout << "(11)查询当前登录状态      (12)查询购物车"<<endl;
    cout << "(13)删除购物车中商品      (14)修改购物车中商品数目"<<endl;
    cout << "(15)购买商品             (16)领取优惠券"<<endl;
    cout << "(17)展示商品             (18)查看购买记录"<<endl;
    cout << "(19)顾客消费数据分析                       "<<endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 0:{
            exit(0);
        }
        case 1: {
            showLogin_User();
            system("pause");
            break;
        }
        case 2: {
            showLogin_Root();
            system("pause");
            break;
        }

        case 3: {
            showRegister();
            system("pause");
            break;
        }

        case 4: {
            showChangePassword();
            system("pause");
            break;
        }

        case 5:{
            showAddProduct();
            system("pause");
            break;
        }

        case 6:{
            showDeleteProduct();
            system("pause");
            break;
        }

        case 7:{
            showChangeProduct();
            system("pause");
            break;
        }

        case 8:{
            showSearchProduct();
            system("pause");
            break;
        }

        case 9:{
            showCreateCart();
            system("pause");
            break;
        }

        case 10:{
            showAddToCart();
            system("pause");
            break;
        }

        case 11:{
            if(LOGIN_STATE==USER){
                cout<<"当前登录状态：USER"<<endl;
                cout<<CURRENT_LOGIN_NAME<<endl;
            }
            else if(LOGIN_STATE==ROOT){
                cout<<"当前登录状态：ROOT"<<endl;
                cout<<CURRENT_LOGIN_NAME<<endl;
            }
            else if(LOGIN_STATE==UNLOGIN)cout<<"当前登录状态：未登录"<<endl;
            system("pause");
            break;
        }

        case 12:{
            shoppingCart_query SCQ;
            SCQ.cart_query();
            system("pause");
            break;
        }

        case 13:{
            showDeleteFromCart();
            system("pause");
            break;
        }

        case 14:{
            showChangeCartNum();
            system("pause");
            break;
        }

        case 15:{
            showPurchase();
            system("pause");
            break;
        }

        case 16:{
            showDiscount();
            system("pause");
            break;
        }

        case 17:{
            showPrintProduct();
            system("pause");
            break;
        }

        case 18:{
            purchaseRecords_Query();
            system("pause");
            break;
        };

        case 19:{
            showDataAnalyze();
            system("pause");
            break;
        }
        default: {
            cout << "输入错误！" << endl;
            exit(0);
        }
    }
}
