//
// Created by lyc on 2024/5/5.
//


//�û�����Ʒ��������ﳵ
#include"ProductManagement.cpp"
#include"sstream"
class shoppingCart_add{
private:
    string product_name;    //��Ʒ����
    string user_name;       //�û�����
    int addNumber;          //�˱����������
public:
    shoppingCart_add(string pname,string uname,int number){
        this->product_name = pname;
        this->user_name = uname;
        this->addNumber = number;
    }

    //��������ﳵ
    void cart_add();
};



void shoppingCart_add::cart_add() {
    ProductManagement p(product_name);
    if(!p.findProduct()){
        //�ڿ����Ҳ�������Ʒ
        cerr<<"��Ʒ�����ڣ�"<<endl;
    }

    else {
        //���ȣ�ͨ����txt����������鹺�ﳵ���Ƿ����и���Ʒ������У���ֻ��Ҫ�������������޸�
        //û�У���������Ʒ����Ŀ
        fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
        string line;
        vector<string> lines;
        int IsProductInCart = 0;    //��־λ��1�����ﳵ���и���Ʒ��0��û��

        string user = "User: " + user_name;
        while (getline(file, line)) {
            if (line == user) {

                while(line!="end"){
                    getline(file,line);
                    if(line==product_name)IsProductInCart=1;
                }
            }
        }
        file.close();


//        if(IsProductInCart==0){
            fstream file1(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
            int symbol = 0;
            while (getline(file1, line)) {
                if (line == user) {
                    symbol = 1;
                }

                //����Ʒ���ڹ��ﳵ�У��������Ʒ��Ŀ
                //ͨ����txt��д����ʵ��
                //ֱ�����ļ�ĩβ������Ʒ
                if(IsProductInCart==0){
                    if (line == "end" && symbol == 1) {
                        lines.push_back(product_name);
                        lines.push_back("number:"+ to_string(addNumber));
                        getline(file1, line);
                        lines.push_back("end");
                        symbol = 0;
                    }
                }
                if(IsProductInCart==1){
                    if(line==product_name){
                        lines.push_back(line);
                        getline(file1,line);
                        size_t found = line.find(':');
                        string numberStr = line.substr(found+1);
                        istringstream iss(numberStr);
                        int number;
                        iss>>number;
                        number = number+addNumber;
                        line = "number:"+to_string(number);
                        symbol=0;
                    }
                }
                lines.push_back(line);
            }
            file1.close();

            ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
            for (string newLine: lines) {
                newfile << newLine << endl;
            }
            newfile.close();
            cout << "��Ʒ���빺�ﳵ�ɹ���" << endl;



            //���´���û��
//        }
//        if(IsProductInCart==0){
//
//        }


//    ProductManagement p(product_name);
//    if(!p.findProduct()){
//        cerr<<"��Ʒ�����ڣ�"<<endl;
//    }
//    else {
//        fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
//        string line;
//        vector<string> lines;
//        int symbol = 0;
//        string user = "User: " + user_name;
//        while (getline(file, line)) {
//            if (line == user) {
//                symbol = 1;
//            }
//            if (line == "end" && symbol == 1) {
//                lines.push_back(product_name);
//                lines.push_back("number: "+ to_string(addNumber));
//                getline(file, line);
//                lines.push_back("end");
//                symbol = 0;
//            }
//            lines.push_back(line);
//        }
//        file.close();
//
//        ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
//        for (string newLine: lines) {
//            newfile << newLine << endl;
//        }
//        newfile.close();
//        cout << "��Ʒ���빺�ﳵ�ɹ���" << endl;
    }
}