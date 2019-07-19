#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace std;
int reverseNum(int x){
    int rev = 0;
    while(x!=0){
        int pop = x%10;
        x/=10;
        //当出现 ans > MAX_VALUE / 10 且 还有pop需要添加 时，则一定溢出
        if(rev>INT_MAX/10 || (rev == INT_MAX/10 && pop>7))//判断溢出。7是2^31 - 1的个位数
            return 0;
        if(rev<INT_MIN/10 || (rev == INT_MIN/10 && pop<-8))//8是-2^31的个位数
            return 0;
        rev = rev*10 + pop;
    }
    return rev;
}
//方法二
int reverseNum2(int x){
    long xl;
    string str = to_string(x);//将数字转为字符串
    int pos = str.find_first_not_of("-");//找到第一个与‘-’不匹配的字符位置
    reverse(str.begin()+pos, str.end());//将除符号位的数字进行反转
    xl = atoi(str.c_str());//将string转换成long
    if(xl>INT_MAX || xl<INT_MIN)
        return 0;
    return xl;


}
int main(){
   cout<<reverseNum2(65);
   system("pause");
   return 0;
}
