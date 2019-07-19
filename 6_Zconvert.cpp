/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:
L     D     R
E   O E   I I
E C   I H   N
T     S     G
 */
#include <iostream>
#include <vector>
using namespace std;
string convert(string s, int num){
    if(num == 1) return s;
    vector<string> rows(min(num, int(s.size())));// 防止s的长度小于行数
    int i = 0;
    bool goDown = false;//默认向上
    for(char c:s){
        rows[i] += c;
        if(i==0 || i == num-1)//首尾行转向
            goDown = !goDown;
        i += goDown ? 1 : -1;//向下时i++,转向后i--;
    }
    string ret;
    for(string row:rows)
        ret += row;
    return ret;
}

int main(){
   
   system("pause");
   return 0;
}
