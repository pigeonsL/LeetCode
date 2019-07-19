/*1.两数之和 */
/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 */
#include <iostream>
#include <windows.h>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int n){
        map<int,int> mp;//存放数组
        vector<int> b(2, -1);//存放结果
        for(int i = 0; i<nums.size();i++){
            //将数组插入到hash map 的同时检查是否有满足条件的元素
            if(mp.count(n-nums[i])>0){
                b[0] = i;
                b[1] = mp[n-nums[i]];
                break;
            }
            mp[nums[i]] = i;//将数组存放到map中
        }
        return b;
    }
};
int main(){
   
   system("pause");
   return 0;
}
