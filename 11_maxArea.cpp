/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 */
#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int>& h){
    int i = 0,j = h.size()-1;
    int maxarea = 0;
    while(i<j){
        maxarea = max(maxarea, min(h[i], h[j])*(j-i));
        if(h[i]<h[j])
            i++;
        else
            j--;
    }
    return maxarea;
}
int main(){
    vector<int> h={1,8,6,2,5,4,8,3,7};
    int res = maxArea(h);
    cout<<res<<endl;
    system("pause");
    return 0;
}
