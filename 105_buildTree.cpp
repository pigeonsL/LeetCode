/*根据一棵树的前序遍历与中序遍历构造二叉树 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        //递归出口
        if(pre.empty() || in.empty())
            return NULL;
        //root节点
        TreeNode* root = new TreeNode(pre[0]);
        // 查找中序遍历中根节点的索引值
        int index = 0;
        for(int i = 0;i<in.size();i++){
            if(in[i] == pre[0]){
                index = i;
                break;
            }
        }
        // 先序遍历和中序遍历的左右子树vector
        vector<int> pre_left, pre_right, in_left, in_right;
        for(int i = 0;i<index;i++){
            pre_left.push_back(pre[i+1]);
            in_left.push_back(in[i]);
        }
        for(int i = index+1;i<pre.size();i++){
            pre_right.push_back(pre[i]);
            in_right.push_back(in[i]);
        }
        
        root->left = buildTree(pre_left,in_left);//重建左子树
        root->right = buildTree(pre_right, in_right);//右子树
        return root;
    }
};
int main(){
   
   system("pause");
   return 0;
}
