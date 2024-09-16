//
// Created by lyc on 2024/5/5.
//


//删除购物车中的商品
#include"ProductManagement.cpp"

class shoppingCart_delete{
private:
    string cd_name;     //待删商品的名称
public:
    shoppingCart_delete(string name){
        this->cd_name = name;
    }

    //删除
    void cart_delete();
};




void shoppingCart_delete::cart_delete() {
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    string line/*,line1*/;
    vector<string>lines;
    int symbol=0;   //没用
    int isFind = 0; //标志位：判断购物车中是否存在该商品
//    while(getline(file,line)){
//        if(line=="Cart"){
//            getline(file,line1);
//            if(line1=="User: "+cd_name){
//                while(line!="Cart"){
//                    getline(file,line1);
//                }
//            }
//        }
//        lines.push_back(line);
//    }

//读写文件
    while(getline(file,line)){
        if(line=="User: "+CURRENT_LOGIN_NAME)symbol=1;
        if(line==cd_name){
            isFind =  1;
            //如果找到了该商品，直接忽略两行信息（分别对应名称和数量），从而删除
            getline(file,line);
            getline(file,line);
        }
        symbol=0;
        lines.push_back(line);
    }
    if(isFind==0){
        cerr<<"商品不存在!"<<endl;
        return;
    }
    file.close();

    //将修改后的信息写回文件
    ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
    for(string newLine:lines){
        newfile<<newLine<<endl;
    }
    newfile.close();
    cout<<"删除成功！"<<endl;
}