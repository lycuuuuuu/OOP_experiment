//
// Created by lyc on 2024/5/6.
//


//这也是测试文件，不用理会
ProductManagement p(product_name);
if(!p.findProduct()){
cerr<<"商品不存在！"<<endl;
}
else {

fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
string line;
vector<string> lines;
int IsProductInCart = 0;
//        int symbol = 0;
string user = "User: " + user_name;
while (getline(file, line)) {
if (line == user) {
//                symbol = 1;
while(line!="end"){
getline(file,line);
if(line==product_name)IsProductInCart=1;
}
}
}
file.close();
if(IsProductInCart==0)




fstream file(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
string line;
vector<string> lines;
int symbol = 0;
string user = "User: " + user_name;
while (getline(file, line)) {
if (line == user) {
symbol = 1;
}
if (line == "end" && symbol == 1) {
lines.push_back(product_name);
lines.push_back("number: "+ to_string(addNumber));
getline(file, line);
lines.push_back("end");
symbol = 0;
}
lines.push_back(line);
}
file.close();

ofstream newfile(R"(C:\Users\lyc\Desktop\2\2.2\OOP\OOP_experiment\experiment_3\shoppingCart.txt)");
for (string newLine: lines) {
newfile << newLine << endl;
}
newfile.close();
cout << "商品加入购物车成功！" << endl;