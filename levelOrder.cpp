#include <iostream>
#include <vector>
#include <queue>
/*给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。 */
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
    vector< vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(!root)
            return vec;
        
        queue<TreeNode*> que;
        TreeNode* fr;//当前节点
        que.push(root);
        while(!que.empty()){
            vector<int> a;
            int len = que.size();
            for(int i=0;i<len;i++){
                fr = que.front();
                a.push_back(fr->val);
                que.pop();
                if(fr->left) que.push(fr->left);
                if(fr->right) que.push(fr->right);
            }
            vec.push_back(a);
        }
        return vec;
    }
};