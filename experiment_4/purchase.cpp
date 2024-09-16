//
// Created by lyc on 2024/5/12.
//


//这个类用来处理各种关于购买商品的事项
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\productManagement.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart_query.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_4\discount.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_5\purchaseRecords.cpp"
class purchase{
private:

public:
//    void showTotalPrice();
    void buyProduct();      //购买商品
    void clearCart();       //一次性清空购物车
    void clearProductFromCart(int number1,int number2);//number1:商品在购物车中的序号;number2:购买数量
                                                       //购买完毕后，从购物车中清除该商品
    void clearProductFromProduct(string pname,int number);//修改库存，pname：商品名称，number：购买的数量
};



//一次性清空购物车
void purchase::clearCart(){
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    string line;
    vector<string>lines;

    //从购物车中读取全部商品,并且全部忽略，再写回其它内容，从而做到清空全部
    //读操作
    while(getline(file,line)) {
        if (line == "User: " + CURRENT_LOGIN_NAME) {
            lines.push_back(line);
            getline(file,line);
            lines.push_back(line);
            while (line != "end")getline(file, line);
        }
        lines.push_back(line);
    }

    //写操作
    ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    for (string newLine: lines) {
        newfile << newLine << endl;
    }
    newfile.close();
    cout<<"已清空！"<<endl;

}



//修改库存，pname：商品名称，number：购买的数量
void purchase::clearProductFromProduct(std::string pname, int buyNumber) {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    string line;
    vector<string>lines;

    //根据给出的名称和固定的格式，去检索商品所在位置，并读取出剩余的库存数，转化为整型，减去购买数量后，再写回库中
    while(getline(file,line)){
        if(line=="name:  "+pname){
            lines.push_back(line);
            getline(file,line);
            lines.push_back(line);
            getline(file,line);
            lines.push_back(line);
            getline(file,line);
            string number_string;
            for(int i=7;i<line.length();i++){   //读取库存，这里还是字符串的形式
                number_string.push_back(line[i]);
            }
//            cout<<"这里没问题"<<endl;  //这是debug时用的标记，请忽略
            int number = stoi(number_string);   //转化为整型
//            cout<<"这里没问题"<<endl;
            number = number - buyNumber;        //减去购买数量
            lines.push_back("stock: "+ to_string(number));      //再转回字符串，放回容器中
        }
        else{
            lines.push_back(line);
        }
    }
    file.close();

    //将修改了的内容写回去
    ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    for(string newLine:lines){
        newfile<<newLine<<endl;
    }
    newfile.close();
    cout<<"库存修改完成!"<<endl;
}



//从购物车中清除某项商品（当购买数量少于购物车中数量的话，只会修改数量）
void purchase::clearProductFromCart(int number1,int number2) {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    string line;
    vector<string>lines;
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME){
            lines.push_back(line);
            for(int i=0;i<=2*(number1-1);i++){
                getline(file,line);
                lines.push_back(line);
            }
            shoppingCart_query SCQ;
            int totalNumber = SCQ.getNumber(number1);
            if(totalNumber==number2){
                getline(file,line);
                clearProductFromProduct(line,number2);
                getline(file,line);
//                cout<<"......"<<endl<<"......    此处省去支付阶段"<<endl<<"......"<<endl;
//                cout<<"购买成功！正在修改商品信息"<<endl;
            }
            else if(totalNumber<number2){
                cout<<"当前购物车中没有这么多商品!"<<endl;
                return;
            }
            else if(totalNumber>number2){
                getline(file,line);
                lines.push_back(line);
                clearProductFromProduct(line,number2);
                string restNumber = to_string(totalNumber-number2);
                lines.push_back("number:"+restNumber);
                getline(file,line);
//                cout<<"......"<<endl<<"......    此处省去支付阶段"<<endl<<"......"<<endl;
//                cout<<"购买成功！正在修改商品信息"<<endl;
            }
            getline(file,line);
        }
        lines.push_back(line);
    }
    file.close();

    ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    for (string newLine: lines) {
        newfile << newLine << endl;
    }
    newfile.close();
    cout<<"商品信息已修改!"<<endl;
}


//购买商品
void purchase::buyProduct() {
    shoppingCart_query SCQ;     //先打印一下购物车，让顾客选择购买
    if(SCQ.cart_query()==false){
        return;
    }

    cout<<endl;
    cout<<"请选择需要购买的商品"<<endl<<"(输入序号即可,如：1、123。)"/*若要全部购买,请输入“all”)"*/<<endl;
    string choice;
    cin>>choice;
//    if(choice=="all"){
//        cout<<"购买全部商品"<<endl;
//        cout<<"......"<<endl<<"......    此处省去支付阶段"<<endl<<"......"<<endl;
//        cout<<"购买成功！正在清空购物车"<<endl;
//        clearCart();
//    }
//    else {

         char singleChoice;     //顾客可以输出一串序号，我会把它分解为一个一个序号，一个一个处理，这个变量就用来储存单个的信号
         double totalCost = 0;  //总价

         //一个一个序号处理，依次交互获取购买数量，并输出需要的价钱
         for(int i=0;i<choice.length();i++){
             singleChoice = choice[i];
             int choice_number = singleChoice-'0';
             cout<<"商品"<<choice_number<<endl<<"请输入要购买的数量"<<endl;
             int purchaseNumber;
             cin>>purchaseNumber;
             cout<<"花费"<<purchaseNumber*SCQ.getPrice(choice_number)<<"元"<<endl;
             totalCost = totalCost + purchaseNumber*SCQ.getPrice(choice_number);
             purchaseRecords PR(choice_number,purchaseNumber);
             PR.addRecord();
             clearProductFromCart(choice_number,purchaseNumber);
         }
         discount D;
         go:
    //如果用户没有优惠券的话，直接消费，显示总价
         if(D.getDiscountNumber()<=0){
             cout<<"无优惠券可用"<<endl;
             cout<<"总共花费"<<totalCost<<"元"<<endl;
         }

         //有优惠券的话，询问是否使用，展示已有的优惠券，让顾客选择
         else{
             cout<<"是否使用优惠券?(请回答1或0)"<<endl;
             char ans;
             cin>>ans;
             if(ans=='1'){
                 double priceAfterDis = D.useDiscount(totalCost);
                 if(priceAfterDis==-1){
                     goto go;
                 }

                 //展示原价，展示优惠后的价格
                 cout<<"优惠前"<<totalCost<<"元"<<endl;
                 cout<<"优惠后"<<priceAfterDis<<"元"<<endl;
             }
             if(ans=='0'){
                 //不使用优惠券
                 cout<<"不使用优惠券"<<endl;
                 cout<<"总共花费"<<totalCost<<"元"<<endl;
             }
         }


         //以下代码请忽略，是我的废案

//        int choice_number = stoi(choice);
//        cout<<"请输入要购买的数量"<<endl;
//        int purchaseNumber;
//        cin>>purchaseNumber;
//        cout<<"花费"<<purchaseNumber*SCQ.getPrice(choice_number)<<"元"<<endl;
//    }
}

//void purchase::showTotalPrice() {
//    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
//    string line;
//    while(getline(file,line)){
//        if()
//    }
//}

//void purchase::buyproduct() {
//    shoppingCart_query SCQ;
//    SCQ.cart_query();
//
//}