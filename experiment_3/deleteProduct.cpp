//
// Created by lyc on 2024/5/5.
//


//����Աɾ����Ʒ
#include"ProductManagement.cpp"
class deleteProduct{
private:
    string d_name;//����

public:
    deleteProduct(string name){
        this->d_name = name;
    }

    //ɾ����Ʒ
    void deleteP();
};



void deleteProduct::deleteP() {


    //ͨ����txt�ļ����޸ģ���д����������ʵ����Ʒ��ɾ��
    fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    if(!file){
        cerr<<"Unable to open file"<<endl;
        EXIT_FAILURE;
        //���ļ�ʧ�ܡ��������˳�
    }
    string line,line1;
    vector<string>lines;

    //���ݹ̶��ĸ�ʽ�͹ؼ��ʣ���������Ʒ��Ϣ����λ�ã�Ȼ����Խ��������У��������ǷŽ�����������������ɾ��
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


    //���������µ���Ϣд���ļ������ں�����4����Ʒ��Ϣ��������Ȼ���ᱻд��ȥ����Ӵ���ʧ
    ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\product.txt)");
    for(string newLine:lines){
        newfile<<newLine<<endl;
    }
    newfile.close();
    cout<<"ɾ���ɹ���"<<endl;

}