#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

/*
只要节点数是相同的，对应能够产生的二叉搜索树的数量就是相同的
对于n个结点，除去根节点，还剩余n-1个结点，因此左右子树的结点数分配方式如下所示：
(0,n-1), (1,n-2), (2, n-3), ....(n-1,0)
则可以依次计算得到n个结点时二叉树的种类，即：
dp(n)=dp(0)*dp(n-1)+dp(1)*dp(n-2)+dp(2)*dp(n-3)+...+dp(n-1)*dp(0)
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n;i++)
            for(int j = 0; j<i;j++)
                dp[i]+=dp[j]*dp[i-1-j];
        return dp[n];
    }
};
int main(){
   

   system("pause");
   return 0;
}
