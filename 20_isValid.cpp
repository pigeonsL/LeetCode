/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 */
#include <iostream>
#include <map>
#include <stack>
using namespace std;
bool isValid(string s){
    int len = s.length();
    if(len%2 != 0) return false;
    map<char,char> mp;
    mp.insert(map<char,char>::value_type(')','('));
    mp.insert(map<char,char>::value_type(']','['));
    mp.insert(map<char,char>::value_type('}','{'));
    stack<char> ss;
    for(int i = 0;i<len;i++){
        if(s[i] == '[' || s[i] == '(' || s[i] == '{')
            ss.push(s[i]);
        else if(s[i] == ']' || s[i] == ')' || s[i] == '}'){
            if(ss.empty()) return false;
            if(mp[s[i]] == ss.top()){
                ss.pop();
                continue;
            }
            else
                return false;
        }
    }
    if(ss.empty()) 
        return true;
    else
        return false;
}
int main(){
    
    system("pause");
    return 0;
}
