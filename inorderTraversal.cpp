/*二叉树的中序遍历 */
#include <iostream>
#include <windows.h>
#include <vector>
#include <stack>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> s;
        while(root!=NULL || !s.empty()){
            //遍历左子树，直至为空
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            root = s.top();
            vec.push_back(root->val);
            s.pop();
            root=root->right;
        }
    }
};
