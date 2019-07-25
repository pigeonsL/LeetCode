/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int len = nums.size();
    if(len<3)
        return {};
    sort(nums.begin(), nums.end());
    int ans = nums[0]+nums[1]+nums[2];
    for(int i=0;i<len;i++){
        int l = i+1, r = len-1;
        while(l<r){
            int sum = nums[i]+nums[l]+nums[r];
            if(abs(target-sum)<abs(target-ans))
                ans = sum;
            if(sum>target)
                r--;
            else if(sum<target)
                l++;
            else 
                return ans;
        }
    }
    return ans;        
}
int main(){
    
    system("pause");
    return 0;
}
