//
// Created by lyc on 2024/4/29.
//

//���ļ���Ҫ�����˻��������棬û��������

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
    cout << "�������û��˺�" << endl;
    cin >> account_u;
    cout << "�������û�����" << endl;
    cin >> password_u;
    login l1(account_u,password_u);
    l1.loginUser();
}
void showLogin_Root(){
    string account_r;
    string password_r;
    cout << "���������Ա�˺�" << endl;
    cin >> account_r;
    cout << "���������Ա����" << endl;
    cin >> password_r;
    login l2(account_r,password_r);
    l2.loginRoot();
}


void showRegister(){
        string account_register;
        string password_register;
    Go_1:
        cout << "�������˺�" << endl;
        cin >> account_register;
    Go_2:
        cout << "����������" << endl;
        cin>>password_register;
        Register R(account_register,password_register);
        int r = R.RegisterUser();
        if(r == 1)goto Go_1;
        if(r == 2)goto Go_2;
}

void showChangePassword(){
    string account,password;
    cout<<"��������Ҫ�޸�������˺�"<<endl;
    cin>>account;
    cout<<"�������µ�����"<<endl;
    cin>>password;
    ChangePassword C(account,password);
    C.ChangeP();
}

void showAddProduct(){
    ProductManagement pm("");
    pm.printProduct();
    cout<<"������Ҫ��ӵ���Ʒ"<<endl;
    string name,detail;
    double price;
    int stock;
    cout<<"��Ʒ����"<<endl;
    cin>>name;
    cout<<"��Ʒ�۸�"<<endl;
    cin>>price;
    cout<<"��Ʒ����"<<endl;
    cin>>detail;
    cout<<"��Ʒ���"<<endl;
    cin>>stock;
    addProduct A(name,price,detail,stock);
    A.addP();
}

void showDeleteProduct(){
    ProductManagement pm("");
    pm.printProduct();
    cout<<"������Ҫɾ������Ʒ������"<<endl;
    string name;
    cin>>name;
    deleteProduct D(name);
    D.deleteP();
}

void showChangeProduct(){
    ProductManagement pm("");
    pm.printProduct();
    cout<<"��������޸���Ʒ������"<<endl;
    string name,choice;
    string name_change;
    string detail_change;
    string price_change;
    string stock_change;
    cin>>name;
    changeProduct C(name);
    cout<<"��ѡ�������޸ĵ�����(�ɶ�ѡ)"
          "1.���� 2.�۸� 3.���� 4.���"<<endl;
    cin>>choice;
    for (std::string::iterator it = choice.begin(); it != choice.end(); ++it) {
        if(*it=='1'){
            cout<<"�޸�����\n�������޸ĺ������"<<endl;
            cin>>name_change;
            C.changeP(name_change,1);
        }
        if(*it=='2'){
            cout<<"�޸ļ۸�\n�������޸ĺ�ļ۸�"<<endl;
            cin>>price_change;
            C.changeP(price_change,2);
        }
        if(*it=='3'){
            cout<<"�޸�����\n�������޸ĺ������"<<endl;
            cin>>detail_change;
            C.changeP(detail_change,3);
        }
        if(*it=='4'){
            cout<<"�޸Ŀ��\n�������޸ĺ�Ŀ��"<<endl;
            cin>>stock_change;
            C.changeP(stock_change,4);
        }
        /*else{
            cerr<<"�������!"<<endl;
            exit(0);
        }*/
    }
    cout<<"�޸ĳɹ���"<<endl;
}

void showSearchProduct(){
    cout<<"������Ҫ��ѯ��Ʒ������"<<endl;
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
        cerr<<"��ǰ״̬Ϊ����Ա�������л����û���"<<endl;
    }
    else if(LOGIN_STATE==UNLOGIN){
        cerr<<"��δ��¼�����ȵ�¼��"<<endl;
    }
}

void showAddToCart(){
    if(LOGIN_STATE==UNLOGIN){
        cerr<<"��δ��¼!"<<endl;
        return;
    }
    ProductManagement pm("");
    pm.printProduct();
    cout<<"������Ҫ���빺�ﳵ����Ʒ����"<<endl;
    string pname;
    cin>>pname;
    cout<<"�������������"<<endl;
    int number;
    cin>>number;
    if(LOGIN_STATE==USER) {
        shoppingCart_add SCA(pname,CURRENT_LOGIN_NAME,number);
        SCA.cart_add();
    }
    else if(LOGIN_STATE==ROOT){
        cerr<<"��ǰ״̬Ϊ����Ա�������л����û���"<<endl;
    }
    else if(LOGIN_STATE==UNLOGIN){
        cerr<<"��δ��¼�����ȵ�¼��"<<endl;
    }

}

void showDeleteFromCart(){
    shoppingCart_query SCQ;
    int symbol=1;
    if(SCQ.cart_query()==false){
        return;
    }

    cout<<"��������Ҫɾ������Ʒ����"<<endl;
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
    cout<<"������Ҫ�޸Ĺ�����Ŀ����Ʒ����"<<endl;
    string name;
    cin>>name;
    cout<<"�������޸ĺ����Ŀ"<<endl;
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
        cerr<<"���ȵ�¼!"<<endl;
        return;
    }
    cout<<"��ȡ�ɹ�!"<<endl;
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
        cerr<<"���ȵ�¼��"<<endl;
        return;
    }
    purchaseRecords PR;
    cout<<"�����¼���£�"<<endl;
    PR.queryRecords();
}

void showDataAnalyze(){
    if(LOGIN_STATE==UNLOGIN){
        cerr<<"���ȵ�¼��"<<endl;
        return;
    }
    cout<<"�˿���������"<<endl;
    cout<<"�����ò�ѯ��ʼʱ��(��ʽ 2024-01-01-00:00:00)"<<endl;
    string sTime;
    cin>>sTime;

    cout<<"�����ò�ѯ����ʱ��(��ʽ 2024-01-01-00:00:00)"<<endl;
    string eTime;
    cin>>eTime;
    DataAnalyze DA(sTime,eTime);
    DA.Analyze();
}

void showMenu() {
    cout << "----------------------------" << endl;
    cout << "-----------��¼ϵͳ-----------" << endl;
    cout << "---------(0)�˳�ϵͳ----------" <<endl;
    cout << "(1)�û���¼              (2)����Ա��¼"  << endl;
    cout << "(3)�û�ע��              (4)�û��޸�����" << endl;
    cout << "(5)�����Ʒ              (6)ɾ����Ʒ"<<endl;
    cout << "(7)�޸���Ʒ��Ϣ           (8)��ѯ��Ʒ��Ϣ"<<endl;
    cout << "(9)�������ﳵ            (10)�����Ʒ�����ﳵ"<<endl;
    cout << "(11)��ѯ��ǰ��¼״̬      (12)��ѯ���ﳵ"<<endl;
    cout << "(13)ɾ�����ﳵ����Ʒ      (14)�޸Ĺ��ﳵ����Ʒ��Ŀ"<<endl;
    cout << "(15)������Ʒ             (16)��ȡ�Ż�ȯ"<<endl;
    cout << "(17)չʾ��Ʒ             (18)�鿴�����¼"<<endl;
    cout << "(19)�˿��������ݷ���                       "<<endl;
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
                cout<<"��ǰ��¼״̬��USER"<<endl;
                cout<<CURRENT_LOGIN_NAME<<endl;
            }
            else if(LOGIN_STATE==ROOT){
                cout<<"��ǰ��¼״̬��ROOT"<<endl;
                cout<<CURRENT_LOGIN_NAME<<endl;
            }
            else if(LOGIN_STATE==UNLOGIN)cout<<"��ǰ��¼״̬��δ��¼"<<endl;
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
            cout << "�������" << endl;
            exit(0);
        }
    }
}
