/*
给定一个没有重复数字的序列，返回其所有可能的全排列。
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    backtrack(nums,res,0);
    return res;
}
void swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void backtrack(vector<int> &nums,vector<vector<int>> &res,int i){
    if(i==nums.size())
        res.push_back(nums);
    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        backtrack(nums,res,i+1);
        swap(nums[i],nums[j]);
    }
}
int main(){
    
    system("pause");
    return 0;
}
