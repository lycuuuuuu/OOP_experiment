//
// Created by lyc on 2024/5/12.
//


//�����ʵ�����¹���
//�Ż�ȯ��������ȡ��
//��txt�ļ��洢�Ż�ȯ��Ϣ
//�Ż�ȯ����

//������������ȯ������ȯ��ֱ��ȯ������ȯ
#pragma once
#include"random"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\productManagement.cpp"
class discount{
private:
//    int whichDiscount;//0:����ȯ��1��ֱ��ȯ��2������ȯ
//    double number_discount;
//    double number_sub;
//    double fullNumber_FTS;
//    double subNumber_FTS;
public:
//    discount(int wd){
//        this->whichDiscount = wd;
////        this->number_discount = nd;
////        this->number_sub = ns;
////        this->fullNumber_FTS  = fnf;
////        this->subNumber_FTS = snf;
//    }
//    int judgeDiscount();
    void sendDiscount_random(int wd);   // ��������Ż�ȯ
    void updateDiscount(int wd,int nd,int ns,int fnf,int snf);  //�����Ż�ȯ��
    int getDiscountNumber();    //���ص�ǰ�û�ӵ���Ż�ȯ����
    void printDiscount();       //��ӡ�û�ӵ�е������Ż�ȯ
    double useDiscount(double price);   //ʹ���Ż�ȯ
    void deleteDiscount(int number);    //ɾ���Ż�ȯ
};
//int discount::judgeDiscount(){
//
//}



//�����Ż�ȯ�⣬ͨ���ı���д����ʵ��
//wd:�Ż�ȯ���࣬0���ۿۣ�1��ֱ����2������
//nd:�ۿ�ȯ��ֵ���ۿۣ�
//ns:ֱ��ȯ��ֵ
//fnf��snf:����ȯ��ֵ����fnf��snf
//��ֵ���ֶ���ȱʡֵ����Ϊ��ʱ����ȷ������һ��ȯ
void discount::updateDiscount(int wd,int nd = 0,int ns = 0,int fnf = 0,int snf = 0) {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_4\discount.txt)");
    string line,line1;
    vector<string>lines;
    int symbol_user=0;//��־λ���ж��û��Ƿ������Լ����Ż�ȯ�⣬û�еĻ����Զ�����
    //��txt�ļ����Ż�ȯ�⣩����д���������õ��Ż�ȯ�ؼ��ֲ�ͬ
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME){
            symbol_user=1;
            lines.push_back(line);
            getline(file,line1);
            while(line1!="end"){
                lines.push_back(line1);
                getline(file,line1);
            }
            if(wd==0){
                lines.push_back("discount: "+ to_string(nd)+"%");
            }
            if(wd==1){
                lines.push_back("sub: "+ to_string(ns));
            }
            if(wd==2){
                lines.push_back("full to sub: "+ to_string(fnf)+"-"+ to_string(snf));
            }
            lines.push_back(line1);
        }
        else lines.push_back(line);
    }
    file.close();

    ofstream newfile("C:\\Users\\lyc\\Desktop\\2\\2.2\\OOP\\OOP_experiment\\experiment_4\\discount.txt");
    for (string newLine: lines) {
        newfile << newLine << endl;
    }
    newfile.close();

    //����û�û���Ż�ȯ�⣬���Զ����������չ̶���ʽ
    if(symbol_user==0){
        fstream anotherFile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_4\discount.txt)",ios::app);
        anotherFile<<"Discount"<<endl;
        anotherFile<<"User: "<<CURRENT_LOGIN_NAME<<endl;
        if(wd==0){
            anotherFile<<"discount: "+ to_string(nd)+"%"<<endl;
//            lines.push_back("discount: "+ to_string(nd)+"%");
        }
        if(wd==1){
            anotherFile<<"sub: "+ to_string(ns)<<endl;
//            lines.push_back("sub: "+ to_string(ns));
        }
        if(wd==2){
            anotherFile<<"full to sub: "+ to_string(fnf)<<"-"<<to_string(snf)<<endl;
            lines.push_back("full to sub: "+ to_string(fnf)+"-"+ to_string(snf));
        }
        anotherFile<<"end"<<endl;
    }


    cout<<"�Ż�ȯ����ɹ�!"<<endl;
}




//�û������ȡ�Ż�ȯ����ֵ����������
void discount::sendDiscount_random(int wd) {
    random_device rd;
    mt19937 gen(rd());
    //���������������ȯ��
    //��ͬ��ȯ����Ҫ����ֵ��ͬ������ͳһ������������ʴ˴�ֻ�����������


//
//    // ����һ���ֲ��������Ծ��ȷֲ�Ϊ��
//    uniform_int_distribution<> dis(1, 100); // ����1��100֮�������
//
//    // ���������
//    for (int n = 0; n < 10; ++n) {
//        cout << dis(gen) << ' ';
//    }
//    cout << '\n';


    switch(wd){
        case 0:{
            //�ۿ�ȯ
            uniform_int_distribution<> dis(5,9);    //���������ֵ��5-9֮��
            int discount = dis(gen);
            cout<<"��ϲ����ô���ȯ!"<<endl<<"�ۿ�:"<<discount*10<<"%"<<endl;
            updateDiscount(wd,discount*10);
            break;
        }

        case 1:{
            //ֱ��ȯ
            uniform_int_distribution<> dis(1,5);    //1-5֮��������
            int discount = dis(gen);
            cout<<"��ϲ�����ֱ��ȯ!"<<endl<<"��ֱ���Ż�"<<discount*100<<"Ԫ"<<endl;
            updateDiscount(wd,0,discount*100);
            break;
        }

        case 2:{
            //����ȯ
            uniform_int_distribution<> dis(1,5);    //1-5֮�������
            int fullNumber = dis(gen)*1000;
            int subNumber;
            subNumber = fullNumber/5;   //��X����X/5
            cout<<"��ϲ���������ȯ!"<<endl<<"������"<<fullNumber<<"Ԫ��ֱ���Ż�"<<subNumber<<"Ԫ"<<endl;
            updateDiscount(wd,0,0,fullNumber,subNumber);
            break;
        }

    }
}


//��ȡ�����Ż�ȯ������ͨ���򵥵��ı�������������һ�¼��ɣ��ܼ򵥣�����׸��
int discount::getDiscountNumber() {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_4\discount.txt)");
    int num=-1;
    int symbol_user=0;
    string line;
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME){
            symbol_user=1;
            while(line!="end"){
                getline(file,line);
                num++;
            }
            return num;
        }
    }
    if(symbol_user==0){
        return num;
    }
}


//��ӡ�����Ż�ȯ����������ʵ�֣��ܼ�
void discount::printDiscount() {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_4\discount.txt)");
    string line;
    int num=0;
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME){
            getline(file,line);
            if(line=="end"){cout<<"�����Ż�ȯ!"<<endl;return;}
            cout<<"ӵ�������Ż�ȯ"<<endl;
            do{
                num++;
                cout<<num<<".  "<<line<<endl;
                getline(file,line);
            }while(line!="end");
        }
    }
}



//ɾ���Ż�ȯ����֮ǰ����Ʒɾ�������ﳵɾ��ͬ��ͨ���ı���д��������������������д�أ�����׸��
void discount::deleteDiscount(int number) {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_4\discount.txt)");
    string line;
    vector<string>lines;
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME){
            lines.push_back(line);
            for(int i=0;i<number-1;i++){
                getline(file,line);
                lines.push_back(line);
            }
            getline(file,line);
            getline(file,line);
            lines.push_back(line);
        }
        else{
            lines.push_back(line);
        }
    }
    file.close();

    ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_4\discount.txt)");
    for(string newLine:lines){
        newfile<<newLine<<endl;
    }
    newfile.close();
    cout<<"�Ż�ȯ�����!"<<endl;
}



//ʹ���Ż�ȯ����������Ƚ���Ҫ��֮��Ĺ�����Ʒ���õ�
//�����price:��Ʒԭ���۸�
//����ֵ���Żݺ�۸�
double discount::useDiscount(double price) {
    printDiscount();
    cout<<"��ѡ����Ҫʹ�õ��Ż�ȯ(������ż���)"<<endl;
    int number;
    cin>>number;        //�����û������Ż�ȯ���
    //findDiscount
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_4\discount.txt)");
    string line,line1;

    //���Ż�ȯ����ɾ�����Ż�ȯ
    while(getline(file,line1)){
        if(line1=="User: "+CURRENT_LOGIN_NAME){
            for(int i=0;i<number;i++){
                getline(file,line);
            }
        }
    }


    //judgeDiscount
    //ͨ���ؼ������ж��Ż�ȯ���࣬��������Ӧ�ļ۸�
    if(line[0]=='d'){
        string discount;
        //���ݹ̶��ĸ�ʽ���ӹ̶�λ�ÿ�ʼ��ȡ�ַ�����������ת��Ϊ�Ż�����
        for(int i=10;i<line.length()-1;i++){
            discount.push_back(line[i]);
        }
        deleteDiscount(number);
        //stoi():�������ڵ��ַ���ת��Ϊ����
        return price* stoi(discount)*0.01;
    }
    //���²���������ͬ��
    if(line[0]=='s'){
        string discount;
        for(int i=5;i<line.length();i++){
            discount.push_back(line[i]);
        }
        deleteDiscount(number);
        return price-stoi(discount);
    }
    if(line[0]=='f'){
        string fullNumber_string,discount;
        for(int i=12;i<16;i++){
            fullNumber_string.push_back(line[i]);
        }
        int fullNumber = stoi(fullNumber_string);
        //������Ϊ������ȯ������Ҫ�ж�һ���Ƿ�������������
        if(price<fullNumber){
            cout<<"�Բ���,����������δ��������"<<endl<<"��Ҫ��"<<fullNumber<<"Ԫ�ſ���ʹ�ñ��Ż�ȯ"<<endl;
            return -1;
        }
        for(int i=17;i<line.length();i++){
            discount.push_back(line[i]);
        }
        deleteDiscount(number);
        return price-stoi(discount);
    }
}