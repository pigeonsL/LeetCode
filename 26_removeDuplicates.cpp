/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 */
#include <iostream>
#include <vector>
using namespace std;
//定义一个慢指针i和快指针j,i指向不重复的位置，j指向遍历的元素位置
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for(int j = 1; j<nums.size();j++){
        if(nums[i] != nums[j])
            nums[++i] = nums[j];
    }
    return i+1;
}
int main(){
    
    system("pause");
    return 0;
}
