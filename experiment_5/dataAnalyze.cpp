//
// Created by lyc on 2024/5/27.
//


//��������������û��Ĺ����¼
//���ݸ�����ʱ���
//����ö�ʱ���ڣ��û��Ĺ������༰����
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\ProductManagement.cpp"
#include"unordered_map"
#include"map"
#include"C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart_query.cpp"

//��ö��������ʾ�������Ʒ���࣬��������ʱ��ͺ�ֱ��
//����Ȼ�˴�Ч�����Ǻ����ԣ���Ϊֻ���������ࣩ
enum class type{
    Phone,Fruit
};

//������������ö�������Ӧ���ַ�����������������������������Ϊö��������⣬�޷�ֱ�����
map<type,string> typeToString{
        {type::Phone,"Phone"},
        {type::Fruit,"Fruit"}
};
//enum class name{
//    ��ΪPura7,iPhone19,ƻ��,�㽶
//};


//���������¼
class DataAnalyze{
private:
    string productType; //�������Ʒ���ࣨ�Ϸ�ö������ַ����棩
    string startTime;   //��������ʼʱ��
    string endTime;     //�����Ľ���ʱ��
    string productName; //��Ʒ������
    unordered_map<string,type> name_type;       //��������1����ö���������Ӧ���ַ�����������
    unordered_map<type,double> type_sum;        //��������2������Ʒ����͸���ʱ����ڹ�����ܼ۹�������
public:
    DataAnalyze(string sTime,string eTime); //���캯����ʵ�ֲ������·���������Ļ��Ƚ�ӵ�����ѿ�
    auto getType();     //������Ʒ���ƣ���ȡ��Ʒ����
    void Analyze();     //���������¼
};



DataAnalyze::DataAnalyze(string sTime,string eTime) {
    //��ʼ����������
    name_type = {
            {"iPhone19",type::Phone},
            {"��ΪPura7",type::Phone},
//            {"ƻ��",type::Fruit},
            {"banana",type::Fruit}
    };
    startTime = sTime;
    endTime = eTime;
}


//�����������ӹ��������л�ȡ����
auto DataAnalyze::getType() {
    auto it = name_type.find(productName);//�������ƣ�ȥ�����������ҵ���Ӧ��Ŀ
    return it->second;  //������Ŀ�ĵڶ�������ࣩ��������ö���࣬���Է���ֵ������auto

    //�ϰ��������
//    if(it->second==type::�ֻ�){
//        return "�ֻ�";
//    }
//    else if(it->second==type::ˮ��){
//        return "ˮ��";
//    }
}


//���������¼
void DataAnalyze::Analyze() {

    double sum1=0;//��¼�����ܼ�
    double sum2=0;
    //����������������͸��๺���ܼ۹�������
    type_sum = {
            {type::Phone,sum1},
            {type::Fruit,sum2}
    };
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_5\purchaseRecords.txt)");
    string line,name,number,time;
//��ȡ�����¼
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME){
            while(line!="end"&&name!="end"&&number!="end"&&time!="end"){
                getline(file,name);
                if(name!="end"){
                    getline(file,number);
                    getline(file,time);
                }

                productName = name;

                //�Ƚ�ʱ�䣬���ù����¼�Ƿ��ڸ���ʱ�����
                if(time.compare(startTime)>=0&&time.compare(endTime)<=0){
                    //��ʱ����ڣ���ȥ��ѯ������������ȡ�ܼۣ��޸ĺ��ٴ�Ż�ȥ
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
    cout<<"�� "<<startTime<<" �� "<<endTime<<" ֮��,�û� "<<CURRENT_LOGIN_NAME
    <<" �����Ѽ�¼����"<<endl;
    for(auto it = type_sum.begin();it != type_sum.end();++it){
        string typeInMap = typeToString[it->first];
        cout<<"��Ʒ���ࣺ"<<typeInMap;
        cout<<"     ���ѽ�"<<it->second<<endl;
    }

}

//int main(){
//    CURRENT_LOGIN_NAME="123456789";
//    DataAnalyze D("2024-05-27 00:00:00","2024-05-28 00:00:00");
//    D.Analyze();
//    return 0;
//}



