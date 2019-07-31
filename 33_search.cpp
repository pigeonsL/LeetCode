/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
 */
#include <iostream>
#include <vector>
using namespace std;

//完整,使用异或，不太好理解
int search1(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo == hi && nums[lo] == target ? lo : -1;
}
//方法二，比较好理解
int search1(vector<int>& nums, int target) {
    if(nums.empty()) return -1;
    int l = 0, r = nums.size()-1, mid = 0;
    while(l<=r){
        mid = (l+r)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid]>=nums[l]){//mid在前半段,旋转点在mid之后
            if(target<nums[mid] && target >= nums[l])
                r = mid-1;
            else 
                l = mid+1;
        }
        else{//mid在后半段，旋转点在mid之前
            if(target>nums[mid] && target <=nums[r])
                l = mid+1;
            else 
                r = mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int> vec = {4,5,6,7,0,1,2};
    cout<<search1(vec,4)<<endl;
    system("pause");
    return 0;
}
