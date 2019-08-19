#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//k=链表长度时，不变
//k>len时: k%ken=k
ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL) return head;
    int len = 1;//链表长度
    ListNode* p = head;
    ListNode* pre = head;
    //计算链表长度
    while(p->next != NULL){
        p = p->next;
        len++;
    }//p指向尾节点

    k = len-k%len;//下标k及其以后的节点需要移动到链表首部
    while(k>1){
        pre = pre->next;//pre指向要移动节点的前驱结点
        k--;
    }
    p->next = head;
    head = pre->next;
    pre->next = NULL;
    return head;
}
int main(){
    
    system("pause");
    return 0;
}
