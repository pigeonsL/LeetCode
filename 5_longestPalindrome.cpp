#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for(int i = 0;i<len;i++)
            dp[i][i] = 1;//对角置为1
        int start = 0;
        int maxlen = 1;
        for(int i = len-2;i>=0;i--){
            for(int j = i-1;j<len;j++){
                if(s[i] == s[j]){
                    if(j-i == 1) 
                        dp[i][j] = 2;
                    else{
                        if(j-i > 1) 
                            dp[i][j] = dp[i+1][j-1]+2;
                    }
                    if(maxlen < dp[i][j]){
                        maxlen = dp[i][j];
                        start = i;
                    }
                }
                else
                    dp[i][j]=0;
            }
        }
        return s.substr(start, maxlen);
    }
};
int main(){
    Solution s;
    string str = "babad";
    string substr = s.longestPalindrome(str);
    cout<<substr<<endl;
    system("pause");
    return 0;
}
