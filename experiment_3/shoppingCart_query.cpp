//
// Created by lyc on 2024/5/5.
//


//��ѯ���ﳵ��Ϣ�����ǰѸ��û��Ĺ��ﳵ��ӡһ��
#pragma once
#include"ProductManagement.cpp"
#include"searchProduct.cpp"


class shoppingCart_query{
private:
    vector<string>products; //һ���������·�����
public:
    bool cart_query();      //��ѯ����ӡ���������ﳵ


    void cart_product_query();  //��ѯĳ������ĳЩ����Ʒ����Ϣ
    //�·��ĸ��������Ǹ���cart_product_query��
    double getPrice(string name);
    double getPrice(int number);    //����getPrice�������β�ͬ��ʵ�ֵĹ��ܲ�ͬ���·��ὲ��
    int getNumber(int number);
    int getNumberFromCart(string s);    //����getNumber����Ҳ�ǹ��ܲ�ͬ
};

void shoppingCart_query::cart_product_query() {
    //�˻����������������ﳵ�е�������Ʒ������һ�����˳�򣩣�����ÿ����Ʒֻ�����ƺ͹�������������Ϣ
    //��ʱ�û���Ҫ��ѯ�ĸ���Ʒ�ľ�����Ϣ�����ƣ����ۣ���������棩����������Ӧ�ı�ż��ɣ�����һ������������123�����˺��������β�ѯ1��2��3
    //����Ʒ����Ϣ
    cout<<"������Ҫ��ѯ����Ʒ��Ӧ���"<<endl;
    int num;
    cin>>num;
    string pname = products[num-1];
    searchProduct S(pname);
    S.searchP();
    //searchP:ȥproduct.txt��Ѱ����Ʒ����Ϣ������ӡ����
}


double shoppingCart_query::getPrice(string name) {

    //ȥtxt�ļ��ж�����Ʒ�ļ۸�ͨ����Ʒ���Ƽ�����
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
    //Ϊ���Ϊnumber����Ʒ��ѯ�۸�
    string name = products[number-1];
    double price = getPrice(name);
    return price;
}

//����������ִ�������1234�������Ϊһ��һ�������֣�1��2��3��4�������ڲ�ѯ��Ʒ�ľ�����Ϣ
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
//            cout << "stoiǰû����" << endl;
//            cout << number_string << endl;
            return stoi(number_string);
        }
    }
}


//��ø���Ʒ�ڹ��ﳵ�е�����
int shoppingCart_query::getNumberFromCart(string s) {
    string number_string;
    int number;
    for(int i=7;i<s.length();i++){
        number_string.push_back(s[i]);
    }
    return stoi(number_string);
}


//��ѯ���ﳵ����ӡ���ﳵ��Ϣ������Ϊÿ����Ʒ�����ܼ�
bool shoppingCart_query::cart_query() {
    if(LOGIN_STATE==UNLOGIN){
        //δ��¼״̬�ǲ鲻�����ﳵ��
        cerr<<"��δ��¼!"<<endl;
        return false;
    }

    //ͨ����txt�ļ��Ķ�������ѯ������������¼��Ϣ
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
                //�����Ʒ����
                cout<<"single price:"<<getPrice(line)<<"    ";
                //�����Ʒ�ܼ�
                cout<<"total price:"<<getPrice(line)* getNumberFromCart(line1)<<endl;

                totalPrice = totalPrice + getPrice(line)* getNumberFromCart(line1);
                products.push_back(line);
                getline(file,line);
            }
        }
    }

    if(isFindCart==0){
        //û�д������ﳵ
        cerr<<"δ�ҵ����ﳵ�����ȴ���!"<<endl;
        return false;
    }
    if(num==0){
        //���ﳵ�л�û����Ʒ
        cerr<<"���ﳵ�ڻ�û����Ʒ����ȥ��һ���!"<<endl;
        return false;
    }

    cout<<"Total Price:"<<totalPrice<<endl;//���ﳵ������Ʒ�۸��ܺ�
    file.close();
    cout<<"�Ƿ�Ҫ��ѯ������Ʒ����ϸ��Ϣ?(�ش�1(��)����0(��)��)"<<endl;
    string IsOrNot;
    cin>>IsOrNot;
    if(IsOrNot=="1"){
        cart_product_query();
    }
    return true;
}
