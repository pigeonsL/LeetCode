/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if(matrix.empty()) return ans;
    int u = 0;//上边界
    int d = matrix.size()-1;//下边界
    int l = 0;//左边界
    int r = matrix[0].size()-1;//右边界
    for(;;){
        for(int i = l;i<=r;i++)//向右
            ans.push_back(matrix[u][i]);
        if(++u >d) break;
        for(int i = u;i<=d;i++)//向下
            ans.push_back(matrix[i][r]);
        if(--r<l) break;
        for(int i = r;i>=l;i--)//向左
            ans.push_back(matrix[d][i]);
        if(--d<u) break;
        for(int i = d;i>=u;i--)//向上
            ans.push_back(matrix[i][l]);
        if(++l>r) break;
    }
    return ans;
}
int main(){
    
    system("pause");
    return 0;
}
