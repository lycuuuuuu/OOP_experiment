//
// Created by lyc on 2024/5/5.
//


//检索商品，即便输入不完全正确，也能推测出用户想要的商品并推荐
#pragma once
#include"ProductManagement.cpp"
#include <algorithm>


class searchProduct{
private:
    string s_name;  //键入的查询商品名称
    int minDistance(string p1,string p2);   //这个成员函数主要用于辅助searchP实现推荐功能，并不对外开放
public:
    searchProduct(string name){
        this->s_name = "name:  "+name;
    }

    //搜索商品
    void searchP();
};



int searchProduct::minDistance(string p1, string p2) {
    //功能
    //用户输入商品名称，这个函数把库中每个商品和其对比，找出最接近的那个商品

    //实现
    //最短距离问题
    //看库中哪一个商品，通过最少次的修改（增删改），能等于输入值
    int length1 = p1.length();
    int length2 = p2.length();
    int distance[length1+1][length2+1];

    for (int i = 0; i <= length1; i++) {
        distance[i][0] = i;
    }
    for (int j = 0; j <= length2; j++) {
        distance[0][j] = j;
    }
    for (int i = 1; i <= length1; i++) {
        for (int j = 1; j <= length2; j++) {
//            int cost = (p1[i - 1] == p2[j - 1]) ? 0 : 1;
            if(p1[i-1]==p2[j-1]){
                distance[i][j] = distance[i-1][j-1];
            }
            else{
            distance[i][j] = min({distance[i-1][j]+1,distance[i][j-1]+1,distance[i-1][j-1]+1});
            }}
    }

    return distance[length1][length2];
}



void searchProduct::searchP() {

    //查询，先去txt文件中读，如果正好能找到，则返回

    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    string line;
    string closestProduct;
    int MinDistance = 10000;
    while(getline(file,line)){
        if(line==s_name){
            cout<<line<<endl;
            for(int i=0;i<3;i++){
                getline(file,line);

                cout<<line<<endl;//输出商品信息
            }
            cout<<"查询成功！"<<endl;
            return;
        }

        //若找不到，则调用minDistance，找最接近的商品
        else {
            if (minDistance(s_name, line) <= MinDistance) {
                MinDistance = minDistance( s_name, line);
                closestProduct = line;
            }
        }
    }
    cout<<"请问您要查询的是不是以下商品？(请回答1或0)"<<endl<<closestProduct<<endl;
    int ans;
    cin>>ans;
    if(ans==1){
        this->s_name = closestProduct;
        searchP();
    }
    else{
        cout<<"查询失败！"<<endl;
    }
    file.close();
}

