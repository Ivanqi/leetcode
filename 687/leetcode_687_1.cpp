/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int max_ret= 1;//统计的是结点的个数，默认有一个。
    int func(TreeNode* root,int f){
        if(!root) return 0;
        int l = func(root->left,root->val);
        int r = func(root->right,root->val);
        max_ret = max( max_ret, l+ r + 1);
        if(root->val == f)
            return max(l,r)+1;
        else 
            return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        func(root,-1);
        return max_ret-1;
    }
};