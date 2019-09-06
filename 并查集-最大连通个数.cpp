//作业帮 3 AC
//最大连通个数
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int num=0;
int ori[4][2]={{-1,0},{0,1},{0,-1},{1,0}};//上，右，左，下

//深搜
int dfs(vector<vector<int>>& map, int n, int m){
    if(m<0 || n<0)//n为行，m为列
        return 0;
    if(n>=map.size() || m>=map[0].size())
        return 0;
    if(map[n][m]==1){
        map[n][m]=-1;//搜寻过的点标记为-1
        num++;
    }
    else
        return 0;
    for(int i=0;i<4;++i)
        dfs(map, n+ori[i][0],m+ori[i][1]);//上，右，左，下
    return num;
}

vector<int> getArray(string& str)
{
    vector<int> arr;
    for(int i=0;i<str.size();++i)
        if(str[i]==',')
            str[i]=' ';
    istringstream is(str);
    int tmp;
    while(is>>tmp)
        arr.push_back(tmp);
    return arr;
}
int main()
{
    string str;
    vector<vector<int>> vec;
    vector<int> tmp;
    while(getline(cin,str)){
        tmp=getArray(str);
        vec.push_back(tmp);
    }
    int maxp=0;
    for(int i=0;i<vec.size();++i){
        for(int j=0;j<vec[i].size();++j){
            if(vec[i][j]==1){
                num=0;//新的循环需要将计数清零
                dfs(vec,i,j);
                maxp=max(maxp,num);
            }
            else
                num=0;
        }
    }
    cout<<maxp<<endl;
    return 0;
}