/*
给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
 */
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> vec(n,vector<int>(n,0));
    int u = 0;
    int d = n-1;
    int l = 0;
    int r = n-1;
    int num = 1;
    for(;;){
        for(int i = l;i<=r;i++)
            vec[u][i] = num++;
        if(++u>d) break;
        for(int i = u;i<=d;i++)
            vec[i][r] = num++;
        if(--r<l) break;
        for(int i = r;i>=l;i--)
            vec[d][i] = num++;
        if(--d<u) break;
        for(int i = d;i>=u;i--)
            vec[i][l] = num++;
        if(++l>r) break;
    } 
    return vec;   
}
int main(){
    
    system("pause");
    return 0;
}
