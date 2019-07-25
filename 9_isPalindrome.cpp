/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数
输入: 121
输出: true
 */
#include <iostream>
#include <sstream>
using namespace std;

bool isPalindrome(int x) {
        stringstream ss;
        string str;
        ss<<x;
        ss>>str;
        int i = 0;
        int j = str.length()-1;
        while(i<j){
            if(str[i]==str[j]){
                i++;j--;
            }
            else
                return false;
        }
        return true;
    }
int main(){
    bool is = isPalindrome(121);
    cout<<is<<endl;
    system("pause");
    return 0;
}
