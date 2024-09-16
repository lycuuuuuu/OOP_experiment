//
// Created by lyc on 2024/5/5.
//


//������Ʒ���������벻��ȫ��ȷ��Ҳ���Ʋ���û���Ҫ����Ʒ���Ƽ�
#pragma once
#include"ProductManagement.cpp"
#include <algorithm>


class searchProduct{
private:
    string s_name;  //����Ĳ�ѯ��Ʒ����
    int minDistance(string p1,string p2);   //�����Ա������Ҫ���ڸ���searchPʵ���Ƽ����ܣ��������⿪��
public:
    searchProduct(string name){
        this->s_name = "name:  "+name;
    }

    //������Ʒ
    void searchP();
};



int searchProduct::minDistance(string p1, string p2) {
    //����
    //�û�������Ʒ���ƣ���������ѿ���ÿ����Ʒ����Աȣ��ҳ���ӽ����Ǹ���Ʒ

    //ʵ��
    //��̾�������
    //��������һ����Ʒ��ͨ�����ٴε��޸ģ���ɾ�ģ����ܵ�������ֵ
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

    //��ѯ����ȥtxt�ļ��ж�������������ҵ����򷵻�

    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    string line;
    string closestProduct;
    int MinDistance = 10000;
    while(getline(file,line)){
        if(line==s_name){
            cout<<line<<endl;
            for(int i=0;i<3;i++){
                getline(file,line);

                cout<<line<<endl;//�����Ʒ��Ϣ
            }
            cout<<"��ѯ�ɹ���"<<endl;
            return;
        }

        //���Ҳ����������minDistance������ӽ�����Ʒ
        else {
            if (minDistance(s_name, line) <= MinDistance) {
                MinDistance = minDistance( s_name, line);
                closestProduct = line;
            }
        }
    }
    cout<<"������Ҫ��ѯ���ǲ���������Ʒ��(��ش�1��0)"<<endl<<closestProduct<<endl;
    int ans;
    cin>>ans;
    if(ans==1){
        this->s_name = closestProduct;
        searchP();
    }
    else{
        cout<<"��ѯʧ�ܣ�"<<endl;
    }
    file.close();
}

