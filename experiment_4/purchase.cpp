//
// Created by lyc on 2024/5/12.
//


//���������������ֹ��ڹ�����Ʒ������
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\productManagement.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart_query.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_4\discount.cpp"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_5\purchaseRecords.cpp"
class purchase{
private:

public:
//    void showTotalPrice();
    void buyProduct();      //������Ʒ
    void clearCart();       //һ������չ��ﳵ
    void clearProductFromCart(int number1,int number2);//number1:��Ʒ�ڹ��ﳵ�е����;number2:��������
                                                       //������Ϻ󣬴ӹ��ﳵ���������Ʒ
    void clearProductFromProduct(string pname,int number);//�޸Ŀ�棬pname����Ʒ���ƣ�number�����������
};



//һ������չ��ﳵ
void purchase::clearCart(){
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    string line;
    vector<string>lines;

    //�ӹ��ﳵ�ж�ȡȫ����Ʒ,����ȫ�����ԣ���д���������ݣ��Ӷ��������ȫ��
    //������
    while(getline(file,line)) {
        if (line == "User: " + CURRENT_LOGIN_NAME) {
            lines.push_back(line);
            getline(file,line);
            lines.push_back(line);
            while (line != "end")getline(file, line);
        }
        lines.push_back(line);
    }

    //д����
    ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    for (string newLine: lines) {
        newfile << newLine << endl;
    }
    newfile.close();
    cout<<"����գ�"<<endl;

}



//�޸Ŀ�棬pname����Ʒ���ƣ�number�����������
void purchase::clearProductFromProduct(std::string pname, int buyNumber) {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    string line;
    vector<string>lines;

    //���ݸ��������ƺ͹̶��ĸ�ʽ��ȥ������Ʒ����λ�ã�����ȡ��ʣ��Ŀ������ת��Ϊ���ͣ���ȥ������������д�ؿ���
    while(getline(file,line)){
        if(line=="name:  "+pname){
            lines.push_back(line);
            getline(file,line);
            lines.push_back(line);
            getline(file,line);
            lines.push_back(line);
            getline(file,line);
            string number_string;
            for(int i=7;i<line.length();i++){   //��ȡ��棬���ﻹ���ַ�������ʽ
                number_string.push_back(line[i]);
            }
//            cout<<"����û����"<<endl;  //����debugʱ�õı�ǣ������
            int number = stoi(number_string);   //ת��Ϊ����
//            cout<<"����û����"<<endl;
            number = number - buyNumber;        //��ȥ��������
            lines.push_back("stock: "+ to_string(number));      //��ת���ַ������Ż�������
        }
        else{
            lines.push_back(line);
        }
    }
    file.close();

    //���޸��˵�����д��ȥ
    ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    for(string newLine:lines){
        newfile<<newLine<<endl;
    }
    newfile.close();
    cout<<"����޸����!"<<endl;
}



//�ӹ��ﳵ�����ĳ����Ʒ���������������ڹ��ﳵ�������Ļ���ֻ���޸�������
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
//                cout<<"......"<<endl<<"......    �˴�ʡȥ֧���׶�"<<endl<<"......"<<endl;
//                cout<<"����ɹ��������޸���Ʒ��Ϣ"<<endl;
            }
            else if(totalNumber<number2){
                cout<<"��ǰ���ﳵ��û����ô����Ʒ!"<<endl;
                return;
            }
            else if(totalNumber>number2){
                getline(file,line);
                lines.push_back(line);
                clearProductFromProduct(line,number2);
                string restNumber = to_string(totalNumber-number2);
                lines.push_back("number:"+restNumber);
                getline(file,line);
//                cout<<"......"<<endl<<"......    �˴�ʡȥ֧���׶�"<<endl<<"......"<<endl;
//                cout<<"����ɹ��������޸���Ʒ��Ϣ"<<endl;
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
    cout<<"��Ʒ��Ϣ���޸�!"<<endl;
}


//������Ʒ
void purchase::buyProduct() {
    shoppingCart_query SCQ;     //�ȴ�ӡһ�¹��ﳵ���ù˿�ѡ����
    if(SCQ.cart_query()==false){
        return;
    }

    cout<<endl;
    cout<<"��ѡ����Ҫ�������Ʒ"<<endl<<"(������ż���,�磺1��123��)"/*��Ҫȫ������,�����롰all��)"*/<<endl;
    string choice;
    cin>>choice;
//    if(choice=="all"){
//        cout<<"����ȫ����Ʒ"<<endl;
//        cout<<"......"<<endl<<"......    �˴�ʡȥ֧���׶�"<<endl<<"......"<<endl;
//        cout<<"����ɹ���������չ��ﳵ"<<endl;
//        clearCart();
//    }
//    else {

         char singleChoice;     //�˿Ϳ������һ����ţ��һ�����ֽ�Ϊһ��һ����ţ�һ��һ����������������������浥�����ź�
         double totalCost = 0;  //�ܼ�

         //һ��һ����Ŵ������ν�����ȡ�����������������Ҫ�ļ�Ǯ
         for(int i=0;i<choice.length();i++){
             singleChoice = choice[i];
             int choice_number = singleChoice-'0';
             cout<<"��Ʒ"<<choice_number<<endl<<"������Ҫ���������"<<endl;
             int purchaseNumber;
             cin>>purchaseNumber;
             cout<<"����"<<purchaseNumber*SCQ.getPrice(choice_number)<<"Ԫ"<<endl;
             totalCost = totalCost + purchaseNumber*SCQ.getPrice(choice_number);
             purchaseRecords PR(choice_number,purchaseNumber);
             PR.addRecord();
             clearProductFromCart(choice_number,purchaseNumber);
         }
         discount D;
         go:
    //����û�û���Ż�ȯ�Ļ���ֱ�����ѣ���ʾ�ܼ�
         if(D.getDiscountNumber()<=0){
             cout<<"���Ż�ȯ����"<<endl;
             cout<<"�ܹ�����"<<totalCost<<"Ԫ"<<endl;
         }

         //���Ż�ȯ�Ļ���ѯ���Ƿ�ʹ�ã�չʾ���е��Ż�ȯ���ù˿�ѡ��
         else{
             cout<<"�Ƿ�ʹ���Ż�ȯ?(��ش�1��0)"<<endl;
             char ans;
             cin>>ans;
             if(ans=='1'){
                 double priceAfterDis = D.useDiscount(totalCost);
                 if(priceAfterDis==-1){
                     goto go;
                 }

                 //չʾԭ�ۣ�չʾ�Żݺ�ļ۸�
                 cout<<"�Ż�ǰ"<<totalCost<<"Ԫ"<<endl;
                 cout<<"�Żݺ�"<<priceAfterDis<<"Ԫ"<<endl;
             }
             if(ans=='0'){
                 //��ʹ���Ż�ȯ
                 cout<<"��ʹ���Ż�ȯ"<<endl;
                 cout<<"�ܹ�����"<<totalCost<<"Ԫ"<<endl;
             }
         }


         //���´�������ԣ����ҵķϰ�

//        int choice_number = stoi(choice);
//        cout<<"������Ҫ���������"<<endl;
//        int purchaseNumber;
//        cin>>purchaseNumber;
//        cout<<"����"<<purchaseNumber*SCQ.getPrice(choice_number)<<"Ԫ"<<endl;
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