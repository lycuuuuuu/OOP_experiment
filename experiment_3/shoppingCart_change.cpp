//
// Created by lyc on 2024/5/5.
//


//修改购物车中商品信息（一般就是改数量）
#include"ProductManagement.cpp"

class shoppingCart_change{
private:
    string cc_name;     //待修改商品的名称
    int cc_aimPurchaseNumber;   //修改后的数目
public:
    shoppingCart_change(string name,int aimPurchaseNumber){
        this->cc_name = name;
        this->cc_aimPurchaseNumber = aimPurchaseNumber;
    }

    //修改信息
    void cart_change();
};




void shoppingCart_change::cart_change() {
    //通过对txt文件的读写操作实现
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    string line;
    vector<string>lines;

    //symbol多余
    //symbol_user：标志位，表示用户是否创建了购物车
    //symbol_product：标志位，表示购物车中是否有该商品
    int symbol=0,symbol_user=0,symbol_product=0;

    while(getline(file,line)){
        //先找到当前用户所处位置
        if(line=="User: "+CURRENT_LOGIN_NAME){
            symbol_user=1;
            symbol=1;
        }
        //开始找商品所在位置，并修改数量
        if(line==cc_name&&symbol==1){
            symbol_product=1;
            lines.push_back(line);
            getline(file,line);
            line = "number:" + to_string(cc_aimPurchaseNumber);
        }
        lines.push_back(line);
    }
    if(symbol_user==0){
        cerr<<"该用户尚未创建购物车!"<<endl;
        return;
    }
    if(symbol_product==0){
        cerr<<"该商品尚未加入购物车!"<<endl;
        return;
    }
    file.close();

    //修改后，写回
    ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    for (string newLine: lines) {
        newfile << newLine << endl;
    }
    newfile.close();
    cout<<"修改成功！"<<endl;
}