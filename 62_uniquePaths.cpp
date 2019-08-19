#include <iostream>
#include <vector>
using namespace std;
static int a[101][101] = {0};
int uniquePaths(int m, int n) {
    //m为列，n为行
    if(m<=0 || n<=0) return 0;
    else if(m==1||n==1) return 1;
    else if(m==2 && n==2) return 2;
    else if((m==3 && n==2) || (m==2 && n==3)) return 3;
    if(a[m][n]>0) return a[m][n];
    a[m-1][n] = uniquePaths(m-1,n);
    a[m][n-1] = uniquePaths(m,n-1);
    a[m][n] = a[m-1][n]+a[m][n-1];
    return a[m][n];
}

int main(){
    cout<<uniquePaths(3,2)<<endl;
    system("pause");
    return 0;
}

