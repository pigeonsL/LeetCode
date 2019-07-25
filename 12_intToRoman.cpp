#include <iostream>
#include <vector>
using namespace std;
string intToRoman(int num){
    vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> strs = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string res;
    for(int i = 0; i < values.size(); i++){
        while(num >= values[i]){
            res += strs[i];
            num -= values[i];
        }
    }
    return res;
}
char* intToRoman2(int num){
    char* res = NULL;
    if(num<=0||num>3999) return res;
    res = (char*)malloc(sizeof(char)*16);
    char Rome[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};//1,5,10,50,100,500,1000
    res[15]=0;
    char i=14,j=0,m=0;
    while(num){
        m = num%10;
        num/=10;
        while(1){
            if(m==9) {res[i--] = Rome[j+2]; m=1;}
            else if(m==8){res[i--] = Rome[j]; m--;}
            else if(m==7){res[i--] = Rome[j]; m--;}
            else if(m==6){res[i--] = Rome[j]; m--;}
            else if(m==5){res[i--] = Rome[j+1]; break;}
            else if(m==4){res[i--] = Rome[j+1]; m=1;}
            else if(m==3){res[i--] = Rome[j]; m--;}
            else if(m==2){res[i--] = Rome[j]; m--;}
            else if(m==1){res[i--] = Rome[j]; break;}
            else break;
        }
        j+=2;
    }
    return res+i+1;
}
int main(){
    cout<<intToRoman2(19)<<endl;
    system("pause");
    return 0;
}
        