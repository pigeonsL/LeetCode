#include <iostream>
#include <vector>
using namespace std;

//并查集，输出有几个联通分支
vector<int> pre;//保存节点的前导节点
int find(int root) //查找根结点
{
	int son, tmp;
	son = root;
	while(root != pre[root]) //寻找根结点
		root = pre[root];
	while(son != root) //路径压缩
	{
		tmp = pre[son];
		pre[son] = root;
		son = tmp;
	}
	return root;//返回根节点
}
void merge(int x,int y)
{
    pre[find(y)]=find(x);//将x的主节点赋给y的主节点
}
int findCircleNum(vector<vector<int>>& M) 
{
    int n=M.size();
    pre.assign(n,0);
    for(int i=0;i<n;++i)
        pre[i]=i;//初始化每个节点的前导为本身
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            if(M[i][j])
                merge(i,j);//连接i,j
    int ans=0;
    for(int i=0;i<n;++i)
        if(i==pre[i])//前导节点为本身的代表一个连通分支
            ++ans;
    return ans;
}
int main(){
    vector<vector<int>> M={{1,1,0},{1,1,0},{0,0,1}};
    cout<<findCircleNum(M)<<endl;
    system("pause");
    return 0;
}