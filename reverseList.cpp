/*反转链表 */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy=new ListNode(-1);
        ListNode* pre=dummy;
        dummy->next=head;
        
        for(int i=1;i<m;i++)
            pre=pre->next;//pre用来标记m位置的前一个节点，将作为反转之后的头结点

        ListNode* cur=pre->next;
        for(int i=m;i<n;i++){
            ListNode* t=cur->next;
            cur->next=t->next;
            t->next=pre->next;
            pre->next=t;
        }
        return dummy->next;
    }
};

