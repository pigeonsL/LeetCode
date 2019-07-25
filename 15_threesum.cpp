#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> >res;
    sort(nums.begin(),nums.end());//由小到大排序
    if(nums.empty() || nums.front()>0 || nums.back()<0)
        return {};
    for(int i=0;i<nums.size();i++){
        int fix=nums[i];
        if(fix>0)   break;//最左边的值>0，则后面不可能有比它小的值
        if(i>0 && fix==nums[i-1])
            continue;//重复的基准数则跳过
        //对撞指针
        int l=i+1,r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r]==-fix  ){
                if(l==i+1 || r==nums.size()-1){
                    res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    l++;r--;
                }
                else if(nums[l]==nums[l-1])
                    l++;
                else if(nums[r]==nums[r+1])
                    r--;
                else{
                    res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    l++;r--;
                }
            }
            else if(nums[l]+nums[r]<-fix)
                l++;
            else
                r--;
        }
    }
    return res;
}
/*
    以第i个数为基准，从i+1->len-1之间找合适的其他两个数，采用对撞指针
    如果sum<0:将左指针右移（找不重复的数）
    如果sum>0:将右指针左移（不重复）
*/

vector<vector<int>> threeSum0(vector<int>& nums) {
    vector<vector<int> >res;
    int len = nums.size();
    sort(nums.begin(),nums.end());
    if(len<3 || nums.front()>0 || nums.back()<0)
        return {};
    for(int i = 0;i<len;i++){
        if(nums[i]>0) break;
        if(i>0 && nums[i]==nums[i-1])
            continue;//重复的基准数则跳过
        int l = i+1, r = len-1;
        while(l<r){
            int sum = nums[i]+nums[l]+nums[r];
            if(sum==0)
                res.push_back(vector<int>{nums[i],nums[l],nums[r]});
            if(sum<0)
                while(l<r && nums[l]==nums[++l]);
            else
                while(l<r && nums[r]==nums[--r]);
        }
    }
    return res;
}
int main(){
    
    system("pause");
    return 0;
}
