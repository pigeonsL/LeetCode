#include <iostream>
#include <sstream>
#include <typeinfo>
#include <string>
using namespace std;

int myatoi(string str){
    while(*str.begin() == ' ')
        str.erase(str.begin());
    if(str=="") return 0;
    stringstream ss;
    ss<<str;
    int n;
    ss>>n;
    return n;
}
string myitoa(int n){
    stringstream ss;
    ss<<n;
    string res;
    ss>>res;
    return res;
}
int main(){
    string s = "4567";
    int res = myatoi(s);
    cout<<res<<"type:"<<typeid(res).name()<<endl;
    s = myitoa(res);
    cout<<s<<"type:"<<typeid(s).name()<<endl;
    char c;
    cout<<typeid(c).name()<<endl;
    system("pause");
    return 0;
}
