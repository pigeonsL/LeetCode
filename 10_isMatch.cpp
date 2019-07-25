/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
 */
#include <iostream>
#include <vector>
using namespace std;
bool isMatch(string str, string pattern){
    int len1 = str.size();
    int len2 = pattern.size();
    if(len2 && pattern[0]=='*')//第一个字符为*则退出
        return false;
    vector<vector<bool>> flag(len1+1,vector<bool>(len2+1, false));
    flag[0][0]=true;//边界情况
    //这里flag[i][j]表示pattern[0~j-1]是否可以匹配str[0~i-1],(注意flag[i][j] 对于pattern[j - 1] str[i - 1])
    for(int i = 1; i<=len2;i++){
        if(pattern[i-1] == '*')
            flag[0][i] = flag[0][i-1] || flag[0][i-2];//这是为了解决类似  "" 和 ".*.*a*a*b*"这种情况 因为这种也是符合的
    }
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            //第一种情况
            if ((pattern[j - 1] == str[i - 1]) || (pattern[j - 1] == '.'))
                flag[i][j] = flag[i - 1][j - 1];
            else if (pattern[j - 1] == '*') {//第二种情况，*号要匹配的个数
                if ((str[i - 1] == pattern[j - 2]) || (pattern[j - 2] == '.')) {//str当前字符与前一个字符相同（模式串字符相同或为.）
                    flag[i][j] = (flag[i][j - 2] || flag[i][j - 1] || flag[i - 1][j]);//*号让前面字符出现0次、出现1次、出现2次及以上
                }
                else {
                    flag[i][j] = flag[i][j - 2];//*号只能让前面的字符出现0次
                }
            }
            else {
                flag[i][j] = false;
            }
        }
    }
    return flag[len1][len2];
}
int main(){
    bool is = isMatch("aa","a.");
    cout<<is<<endl;
    system("pause");
    return 0;
}
