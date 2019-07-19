/*
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 */
#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

class Solution {
public:
   int lengthOfLongestSubstring(string s) {
      int len = s.size();
      vector<int> d(256,-1);
      int maxlen = 0, start=-1;
      for(int i = 0; i<len; i++){
         if(d[s[i]]>start)//如果已经存在
            start = d[s[i]];//start表示上一次出现的index
         d[s[i]] = i;//更新字符下标为第2次出现的下标
         maxlen = max(maxlen, i-start);//重复出现到第一次之间的距离
      }
      return maxlen;
   }

};
int main(){
   
   system("pause");
   return 0;
}
