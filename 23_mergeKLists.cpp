/*合并 k 个排序链表，返回合并后的排序链表。
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//暴力法,将所有节点拆下来放进vector中，然后进行排序，之后将排好序的节点链接起来。
ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<ListNode*> longList;
    for(ListNode* start:lists){
        ListNode* p = start;
        while(p != NULL){
            longList.push_back(p);
            p = p->next;
        }
    }
    sort(longList.begin(),longList.end(), [](auto x, auto y){return (x->val < y->val);});
    if(longList.size==0) return NULL;
    for(size_t i = 0;i<longList.size()-1; i++)
        longList[i]->next = longList[i+1];
    longList[longList.size()-1]->next = NULL;
    return longList[0];
}
//使用multimap
ListNode* mergeKLists(vector<ListNode*>& lists) {
    multimap<int,ListNode*> mmp;
    for(ListNode* p:lists){//每个链表的头结点加入map
        if(p != NULL)
            mmp.insert(pair<int,ListNode*>(p->val, p));//multimap会自动对key从小到大排序
    }
    ListNode dummy(-1);//新的链表头
    ListNode* tail = &dummy;//新链表的操作指针
    while(!mmp.empty()){
        multimap<int,ListNode*>::iterator it = mmp.begin();//插入map会根据key排序，所以逐个访问it.begin(),并将其加入新的链表即可
        tail->next = it->second;
        tail = tail->next;
        if(it->second->next != NULL)
            mmp.insert(pair<int,ListNode*>(it->second->next->val,it->second->next));
        mmp.erase(it);//it链接到新的链表上后删除该节点（也是最小的节点）
    }
    tail->next = NULL;
    return dummy.next;
}
int main(){
    
    system("pause");
    return 0;
}
