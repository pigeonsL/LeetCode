/*
输入: num1 = "2", num2 = "3"
输出: "6"
 */
#include <iostream>
#include <vector>
using namespace std;
//乘法原理，竖乘
string multiply(string num1, string num2) {
    int len1 = num1.size(), len2 = num2.size(), p = 0;
    vector<int> bits(len1+len2, 0);
    for(int i = len2-1; i>=0; i--){
        p = len2-1-i;//从个位起
        for(int j = len1-1;j>=0;j--){
            int res = (num2[i]-'0')*(num1[j]-'0')+bits[p];
            if(res >= 10)
                bits[p+1] += res/10;//保存进位
            bits[p++] = res%10;//保存当前位的值
        }
    }
    string ans = "";
    int temp = len1+len2-1;
    while(temp >= 0 && bits[temp] == 0)
        temp--;
    for(int i = 0;i<=temp;i++)
        ans = char(bits[i]+'0')+ans;
    return ans == ""?"0":ans;
}
int main(){
    cout<<multiply("123","456")<<endl;
    system("pause");
    return 0;
}
