/* 最大子序和
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 */
#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int>& nums){
    int ans = nums[0];
    int sum = 0;
    for(int num:nums){
        if(sum>0)
            sum+=num;
        else
            sum = num;
        ans = max(sum,ans);
    }
    return ans;
}
int main(){
    
    system("pause");
    return 0;
}
