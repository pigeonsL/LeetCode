#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    //方法一，递归
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1->val < l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};
//方法二,官方解答，迭代
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    ListNode head = ListNode(-1);//创建栈空间对象
    ListNode* pre = &head;//新链表的操作指针
    while(l1 != NULL && l2 != NULL){
        if(l1->val <= l2->val){
            pre->next = l1;
            l1 = l1->next;
        }
        else{
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    pre->next = l1 != NULL ? l1 : l2;
    return head.next;
}
int main()
{
    cout<<"hello"<<endl;
    return 0;
}
