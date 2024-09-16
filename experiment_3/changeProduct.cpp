//
// Created by lyc on 2024/5/5.
//


//管理员修改商品信息
#include"ProductManagement.cpp"
class changeProduct{
private:
    //因为只涉及到对txt文件的修改，只需要商品名称，然后找到相应的商品，就可以修改其相关信息
    string c_name;//名称
public:
    changeProduct(string name){
        this->c_name = name;
    }


    void changeP(string,int);//修改名字或描述，根据int的值来判别
    //问：int有什么用？
    //答：int一共有1，2，3，4取值，每个取值对应需要修改的信息（名称，单价，描述，库存）

};





void changeProduct::changeP(string String,int N){
    //若N=1，则改名字，等于2则改价格，3修改描述，4修改库存
    string line;
    vector<string>lines;


    //对商品信息的修改，本质还是对txt文件的读写操作，和之前的修改用户账号密码同理，都是根据给定的格式和关键词检索，然后修改，此处不再赘述
    if(N==1){
        fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");

        string name = "name:  "+c_name;

        while(getline(file,line)){
            if(line==name) {
                string newname = "name:  " + String;
                line = newname;
                lines.push_back(line);
                getline(file,line);
            }
            lines.push_back(line);
        }
        file.close();
        c_name = String;
        ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
        for(string newLine:lines){
            newfile<<newLine<<endl;
        }
        newfile.close();
        cout<<"名称修改成功！"<<endl;
    }
    if(N==3){   //这里3和2的顺序错乱了一下，但是不影响功能实现
        fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
        //string line;
        string name = "name:  "+c_name;
        //vector<string>lines;
        while(getline(file,line)){
            if(line==name) {
                lines.push_back(line);
                getline(file,line);
                lines.push_back(line);
                string newdetail = "detail:" + String;
                getline(file,line);
                line = newdetail;
                lines.push_back(line);
                getline(file,line);
            }
            lines.push_back(line);
        }
        file.close();
        ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
        for(string newLine:lines){
            newfile<<newLine<<endl;
        }
        newfile.close();
        cout<<"描述修改成功！"<<endl;
    }
    if(N==2){
        //string line;
        //vector<string>lines;
        fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
        //string line;
        string name = "name:  "+c_name;
        //vector<string>lines;
        while(getline(file,line)){
            if(line==name) {
                lines.push_back(line);
                getline(file,line);
                string newprice = "price: " + String;
                line = newprice;
                lines.push_back(line);
                getline(file,line);
            }
            lines.push_back(line);
        }
        file.close();
        ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
        for(string newLine:lines){
            newfile<<newLine<<endl;
        }
        newfile.close();
        cout<<"价格修改成功！"<<endl;

    }
    if(N==4){
        //string line;
        //vector<string>lines;
        fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
        //string line;
        string name = "name:  "+c_name;
        //vector<string>lines;
        while(getline(file,line)){
            if(line==name) {
                lines.push_back(line);
                getline(file,line);
                lines.push_back(line);
                getline(file,line);
                lines.push_back(line);
                getline(file,line);
                string newstock = "stock: " + String;
                line = newstock;
                lines.push_back(line);
                getline(file,line);
            }
            lines.push_back(line);
        }
        file.close();
        ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
        for(string newLine:lines){
            newfile<<newLine<<endl;
        }
        newfile.close();
        cout<<"库存修改成功！"<<endl;
    }

    //if(N==1)cout<<"名称修改成功！"<<endl;
    //if(N==2)cout<<"价格修改成功！"<<endl;
    //if(N==3)cout<<"描述修改成功!"<<endl;
    //if(N==4)cout<<"库存修改成功!"<<endl;
}


//以下都是我之前写的版本，不舍得删，缅怀一下，可以不用往下看了

/*void changeProduct::changeP(double Double) {
    string line;
    vector<string>lines;
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    //string line;
    string name = "name:  "+c_name;
    //vector<string>lines;
    while(getline(file,line)){
        if(line==name) {
            lines.push_back(line);
            getline(file,line);
            string newprice = "price: " + to_string(Double);
            line = newprice;
            lines.push_back(line);
            getline(file,line);
        }
        lines.push_back(line);
    }
    file.close();

    ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    for(string newLine:lines){
        newfile<<newLine<<endl;
    }
    newfile.close();
    cout<<"价格修改成功！"<<endl;
}

void changeProduct::changeP(int Int) {
    string line;
    vector<string>lines;
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    //string line;
    string name = "name:  "+c_name;
    //vector<string>lines;
    while(getline(file,line)){
        if(line==name) {
            lines.push_back(line);
            getline(file,line);
            lines.push_back(line);
            getline(file,line);
            lines.push_back(line);
            getline(file,line);
            string newstock = "stock: " + to_string(Int);
            line = newstock;
            lines.push_back(line);
            getline(file,line);
        }
        lines.push_back(line);
    }
    file.close();

    ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    for(string newLine:lines){
        newfile<<newLine<<endl;
    }
    newfile.close();
    cout<<"库存修改成功！"<<endl;
}*/