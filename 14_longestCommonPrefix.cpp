/*最长公共前缀
输入: ["flower","flow","flight"]
输出: "fl"
 */
#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty())
        return "";
    int len1 = strs[0].size();
    int index = 0;
    for(int i = 0;i<len1;i++){//单个字符串下标
        for(string s:strs){
            if(s.length()==i || s[index] != strs[0][index])
                return s.substr(0,index);
        }
        index++;
    }
    return strs[0].substr(0,index); 
}
int main(){
    vector<string> str = {"flower","flow","flight"};
    cout<<longestCommonPrefix(str)<<endl;
    system("pause");
    return 0;
}
