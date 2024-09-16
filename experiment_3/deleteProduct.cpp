//
// Created by lyc on 2024/5/5.
//


//管理员删除商品
#include"ProductManagement.cpp"
class deleteProduct{
private:
    string d_name;//名称

public:
    deleteProduct(string name){
        this->d_name = name;
    }

    //删除商品
    void deleteP();
};



void deleteProduct::deleteP() {


    //通过对txt文件的修改（读写操作），来实现商品的删除
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    if(!file){
        cerr<<"Unable to open file"<<endl;
        EXIT_FAILURE;
        //打开文件失败——报错，退出
    }
    string line,line1;
    vector<string>lines;

    //根据固定的格式和关键词，检索到商品信息所在位置，然后忽略接下来四行（不把它们放进容器），就能做到删除
    string name = "name:  "+d_name;
    while(getline(file,line)){
        if(line=="Product"){
            getline(file,line1);
            string flag = line1;
            if(flag==name){
                getline(file,line1);
                getline(file,line1);
                getline(file,line1);
                getline(file,line1);
                //getline(file,line1);
            }
            else if(flag!=name){
                lines.push_back(line);
                lines.push_back(line1);
            }
        }
        else{lines.push_back(line);}
    }
    file.close();


    //将容器内新的信息写回文件，由于忽略了4行商品信息，它们自然不会被写进去，便从此消失
    ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    for(string newLine:lines){
        newfile<<newLine<<endl;
    }
    newfile.close();
    cout<<"删除成功！"<<endl;

}