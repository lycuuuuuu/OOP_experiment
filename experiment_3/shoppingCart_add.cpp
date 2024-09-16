//
// Created by lyc on 2024/5/5.
//


//用户把商品添加至购物车
#include"ProductManagement.cpp"
#include"sstream"
class shoppingCart_add{
private:
    string product_name;    //商品名称
    string user_name;       //用户名称
    int addNumber;          //此变量下面解释
public:
    shoppingCart_add(string pname,string uname,int number){
        this->product_name = pname;
        this->user_name = uname;
        this->addNumber = number;
    }

    //添加至购物车
    void cart_add();
};



void shoppingCart_add::cart_add() {
    ProductManagement p(product_name);
    if(!p.findProduct()){
        //在库中找不到该商品
        cerr<<"商品不存在！"<<endl;
    }

    else {
        //首先，通过对txt读操作，检查购物车中是否已有该商品，如果有，则只需要对其数量进行修改
        //没有，则加入该商品的条目
        fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
        string line;
        vector<string> lines;
        int IsProductInCart = 0;    //标志位：1：购物车中有该商品；0：没有

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

                //若商品不在购物车中，则加入商品条目
                //通过对txt的写操作实现
                //直接在文件末尾加入商品
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
            cout << "商品加入购物车成功！" << endl;



            //以下代码没用
//        }
//        if(IsProductInCart==0){
//
//        }


//    ProductManagement p(product_name);
//    if(!p.findProduct()){
//        cerr<<"商品不存在！"<<endl;
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
//        cout << "商品加入购物车成功！" << endl;
    }
}