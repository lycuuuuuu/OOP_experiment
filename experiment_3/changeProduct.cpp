//
// Created by lyc on 2024/5/5.
//


//����Ա�޸���Ʒ��Ϣ
#include"ProductManagement.cpp"
class changeProduct{
private:
    //��Ϊֻ�漰����txt�ļ����޸ģ�ֻ��Ҫ��Ʒ���ƣ�Ȼ���ҵ���Ӧ����Ʒ���Ϳ����޸��������Ϣ
    string c_name;//����
public:
    changeProduct(string name){
        this->c_name = name;
    }


    void changeP(string,int);//�޸����ֻ�����������int��ֵ���б�
    //�ʣ�int��ʲô�ã�
    //��intһ����1��2��3��4ȡֵ��ÿ��ȡֵ��Ӧ��Ҫ�޸ĵ���Ϣ�����ƣ����ۣ���������棩

};





void changeProduct::changeP(string String,int N){
    //��N=1��������֣�����2��ļ۸�3�޸�������4�޸Ŀ��
    string line;
    vector<string>lines;


    //����Ʒ��Ϣ���޸ģ����ʻ��Ƕ�txt�ļ��Ķ�д��������֮ǰ���޸��û��˺�����ͬ�����Ǹ��ݸ����ĸ�ʽ�͹ؼ��ʼ�����Ȼ���޸ģ��˴�����׸��
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
        cout<<"�����޸ĳɹ���"<<endl;
    }
    if(N==3){   //����3��2��˳�������һ�£����ǲ�Ӱ�칦��ʵ��
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
        cout<<"�����޸ĳɹ���"<<endl;
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
        cout<<"�۸��޸ĳɹ���"<<endl;

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
        cout<<"����޸ĳɹ���"<<endl;
    }

    //if(N==1)cout<<"�����޸ĳɹ���"<<endl;
    //if(N==2)cout<<"�۸��޸ĳɹ���"<<endl;
    //if(N==3)cout<<"�����޸ĳɹ�!"<<endl;
    //if(N==4)cout<<"����޸ĳɹ�!"<<endl;
}


//���¶�����֮ǰд�İ汾�������ɾ���廳һ�£����Բ������¿���

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
    cout<<"�۸��޸ĳɹ���"<<endl;
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
    cout<<"����޸ĳɹ���"<<endl;
}*/