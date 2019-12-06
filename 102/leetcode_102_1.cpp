#include <iostream>
#include <vector>
using namespace std;
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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root, 0);
        return ans;
    }

    void helper(TreeNode* root, int level) {
        if(!root) return;
        if(level>=ans.size()) ans.push_back(vector<int>());
        ans[level].push_back(root->val);
        helper(root->left,level+1);
        helper(root->right,level+1);
    }    
};