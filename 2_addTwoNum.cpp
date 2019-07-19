/*
2.两数相加
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807 
*/
#include <iostream>
#include <windows.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
public:
    ListNode* addTwoNum(ListNode* l1, ListNode* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* head = new ListNode(-1);//存放结果的头结点
        ListNode* l3 = head;
        bool flag = false;
        while(l1!=NULL || l2!=NULL){
            int num = 0;
            if(l1!=NULL){
                num+=l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                num+=l2->val;
                l2 = l2->next;
            }
            if(flag)
                num++;
            l3->next = new ListNode(num%10);
            l3 = l3->next;
            flag = num>9?true:false;
        }
        if(flag)//最后的进位
            l3->next = new ListNode(1);
        return head->next;
    }
};
int main(){
   
   system("pause");
   return 0;
}
