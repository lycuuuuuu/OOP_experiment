//
// Created by lyc on 2024/5/27.
//


//这个类用来分析用户的购买记录
//根据给定的时间段
//输出该段时间内，用户的购买种类及其金额
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\ProductManagement.cpp"
#include"unordered_map"
#include"map"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart_query.cpp"

//用枚举类来表示购买的商品种类，当种类多的时候就很直观
//（当然此处效果不是很明显，因为只用两个种类）
enum class type{
    Phone,Fruit
};

//关联容器，把枚举类和相应的字符串关联起来，方便后续的输出，因为枚举类很特殊，无法直接输出
map<type,string> typeToString{
        {type::Phone,"Phone"},
        {type::Fruit,"Fruit"}
};
//enum class name{
//    华为Pura7,iPhone19,苹果,香蕉
//};


//分析购买记录
class DataAnalyze{
private:
    string productType; //购买的商品种类（上方枚举类的字符串版）
    string startTime;   //给定的起始时间
    string endTime;     //给定的结束时间
    string productName; //商品的名称
    unordered_map<string,type> name_type;       //关联容器1：把枚举类和其相应的字符串关联起来
    unordered_map<type,double> type_sum;        //关联容器2：把商品种类和给定时间段内购买的总价关联起来
public:
    DataAnalyze(string sTime,string eTime); //构造函数，实现部分在下方，放在这的话比较拥挤，难看
    auto getType();     //根据商品名称，获取商品种类
    void Analyze();     //分析购买记录
};



DataAnalyze::DataAnalyze(string sTime,string eTime) {
    //初始化关联容器
    name_type = {
            {"iPhone19",type::Phone},
            {"华为Pura7",type::Phone},
//            {"苹果",type::Fruit},
            {"banana",type::Fruit}
    };
    startTime = sTime;
    endTime = eTime;
}


//关联容器，从关联容器中获取种类
auto DataAnalyze::getType() {
    auto it = name_type.find(productName);//根据名称，去关联容器中找到相应条目
    return it->second;  //返回条目的第二项（即种类），由于是枚举类，所以返回值类型用auto

    //废案，请忽略
//    if(it->second==type::手机){
//        return "手机";
//    }
//    else if(it->second==type::水果){
//        return "水果";
//    }
}


//分析购买记录
void DataAnalyze::Analyze() {

    double sum1=0;//记录购买总价
    double sum2=0;
    //关联容器，把种类和该类购买总价关联起来
    type_sum = {
            {type::Phone,sum1},
            {type::Fruit,sum2}
    };
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_5\purchaseRecords.txt)");
    string line,name,number,time;
//读取购买记录
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME){
            while(line!="end"&&name!="end"&&number!="end"&&time!="end"){
                getline(file,name);
                if(name!="end"){
                    getline(file,number);
                    getline(file,time);
                }

                productName = name;

                //比较时间，看该购买记录是否在给定时间段内
                if(time.compare(startTime)>=0&&time.compare(endTime)<=0){
                    //在时间段内，则去查询关联容器，获取总价，修改后再存放回去
                    auto it = type_sum.find(getType());
                    shoppingCart_query SCQ;

                    string Number;

                    for(int i=7;i<=number.length();i++){
                        Number.push_back(number[i]);
                    }

                    it->second = it->second + stoi(Number) * SCQ.getPrice(productName);

                }

            }
        }
    }

    file.close();
    cout<<"在 "<<startTime<<" 至 "<<endTime<<" 之间,用户 "<<CURRENT_LOGIN_NAME
    <<" 的消费记录如下"<<endl;
    for(auto it = type_sum.begin();it != type_sum.end();++it){
        string typeInMap = typeToString[it->first];
        cout<<"商品种类："<<typeInMap;
        cout<<"     消费金额："<<it->second<<endl;
    }

}

//int main(){
//    CURRENT_LOGIN_NAME="123456789";
//    DataAnalyze D("2024-05-27 00:00:00","2024-05-28 00:00:00");
//    D.Analyze();
//    return 0;
//}



