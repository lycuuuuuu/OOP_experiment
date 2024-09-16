//
// Created by lyc on 2024/5/12.
//


//这个类实现以下功能
//优惠券创建（领取）
//用txt文件存储优惠券信息
//优惠券管理

//我设置了三种券：打折券，直减券，满减券
#pragma once
#include"random"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\productManagement.cpp"
class discount{
private:
//    int whichDiscount;//0:打折券，1：直减券，2：满减券
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
    void sendDiscount_random(int wd);   // 随机生成优惠券
    void updateDiscount(int wd,int nd,int ns,int fnf,int snf);  //更新优惠券库
    int getDiscountNumber();    //返回当前用户拥有优惠券总数
    void printDiscount();       //打印用户拥有的所有优惠券
    double useDiscount(double price);   //使用优惠券
    void deleteDiscount(int number);    //删除优惠券
};
//int discount::judgeDiscount(){
//
//}



//更新优惠券库，通过文本读写操作实现
//wd:优惠券种类，0：折扣，1：直减，2：满减
//nd:折扣券数值（折扣）
//ns:直减券数值
//fnf，snf:满减券数值，满fnf减snf
//数值部分都设缺省值，因为暂时不能确定用哪一种券
void discount::updateDiscount(int wd,int nd = 0,int ns = 0,int fnf = 0,int snf = 0) {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_4\discount.txt)");
    string line,line1;
    vector<string>lines;
    int symbol_user=0;//标志位，判断用户是否建立了自己的优惠券库，没有的话会自动创建
    //对txt文件（优惠券库）进行写操作，不用的优惠券关键字不同
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

    //如果用户没有优惠券库，则自动创建，按照固定格式
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


    cout<<"优惠券保存成功!"<<endl;
}




//用户随机领取优惠券，数值和种类均随机
void discount::sendDiscount_random(int wd) {
    random_device rd;
    mt19937 gen(rd());
    //生成随机数，决定券种
    //不同的券，需要的数值不同，不能统一生成随机数，故此处只生成随机种类


//
//    // 创建一个分布，这里以均匀分布为例
//    uniform_int_distribution<> dis(1, 100); // 生成1到100之间的整数
//
//    // 生成随机数
//    for (int n = 0; n < 10; ++n) {
//        cout << dis(gen) << ' ';
//    }
//    cout << '\n';


    switch(wd){
        case 0:{
            //折扣券
            uniform_int_distribution<> dis(5,9);    //生成随机数值：5-9之间
            int discount = dis(gen);
            cout<<"恭喜您获得打折券!"<<endl<<"折扣:"<<discount*10<<"%"<<endl;
            updateDiscount(wd,discount*10);
            break;
        }

        case 1:{
            //直减券
            uniform_int_distribution<> dis(1,5);    //1-5之间的随机数
            int discount = dis(gen);
            cout<<"恭喜您获得直减券!"<<endl<<"可直接优惠"<<discount*100<<"元"<<endl;
            updateDiscount(wd,0,discount*100);
            break;
        }

        case 2:{
            //满减券
            uniform_int_distribution<> dis(1,5);    //1-5之间随机数
            int fullNumber = dis(gen)*1000;
            int subNumber;
            subNumber = fullNumber/5;   //满X，减X/5
            cout<<"恭喜您获得满减券!"<<endl<<"消费满"<<fullNumber<<"元可直接优惠"<<subNumber<<"元"<<endl;
            updateDiscount(wd,0,0,fullNumber,subNumber);
            break;
        }

    }
}


//获取库中优惠券数量，通过简单的文本读操作，遍历一下即可，很简单，不再赘述
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


//打印所有优惠券，遍历操作实现，很简单
void discount::printDiscount() {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_4\discount.txt)");
    string line;
    int num=0;
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME){
            getline(file,line);
            if(line=="end"){cout<<"暂无优惠券!"<<endl;return;}
            cout<<"拥有以下优惠券"<<endl;
            do{
                num++;
                cout<<num<<".  "<<line<<endl;
                getline(file,line);
            }while(line!="end");
        }
    }
}



//删除优惠券，和之前的商品删除，购物车删除同理，通过文本读写，用容器做缓冲再重新写回，不再赘述
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
    cout<<"优惠券已清除!"<<endl;
}



//使用优惠券，这个函数比较重要，之后的购买商品会用到
//输入的price:商品原本价格
//返回值：优惠后价格
double discount::useDiscount(double price) {
    printDiscount();
    cout<<"请选择需要使用的优惠券(输入序号即可)"<<endl;
    int number;
    cin>>number;        //接收用户键入优惠券序号
    //findDiscount
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_4\discount.txt)");
    string line,line1;

    //从优惠券库中删除该优惠券
    while(getline(file,line1)){
        if(line1=="User: "+CURRENT_LOGIN_NAME){
            for(int i=0;i<number;i++){
                getline(file,line);
            }
        }
    }


    //judgeDiscount
    //通过关键字来判断优惠券种类，并返回相应的价格
    if(line[0]=='d'){
        string discount;
        //根据固定的格式，从固定位置开始读取字符串，并将其转化为优惠数字
        for(int i=10;i<line.length()-1;i++){
            discount.push_back(line[i]);
        }
        deleteDiscount(number);
        //stoi():把括号内的字符串转化为整型
        return price* stoi(discount)*0.01;
    }
    //以下操作和上面同理
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
        //这里因为是满减券，还需要判断一下是否满足消费需求
        if(price<fullNumber){
            cout<<"对不起,您的消费尚未满足条件"<<endl<<"需要满"<<fullNumber<<"元才可以使用本优惠券"<<endl;
            return -1;
        }
        for(int i=17;i<line.length();i++){
            discount.push_back(line[i]);
        }
        deleteDiscount(number);
        return price-stoi(discount);
    }
}