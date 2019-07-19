#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;
/*给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
public:
    vector<TreeNode*> generateTrees(int n){
        vector<TreeNode*> res;
        if(n<1) return res;
        return genBST(1, n);
    }
    vector<TreeNode*> genBST(int start, int end){//返回从start开始，end结尾的元素生成的二叉搜索树的集合
        vector<TreeNode*> res;
        if(start>end) res.push_back(NULL);
        for(int i = start; i<=end; i++){//根节点为i
            vector<TreeNode*> lefts = genBST(start, i-1);//产生左子树
            vector<TreeNode*> rights = genBST(i+1, end);//右子树
            for(auto left:lefts){
                for(auto right:rights){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main(){
   
   system("pause");
   return 0;
}
