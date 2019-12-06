#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> Q;
        if (root) Q.push(root);

        while (Q.size()) {
            ans.push_back(vector<int>());
            int cnt = Q.size();
            for(int i=0;i<cnt;++i){
                TreeNode* cur=Q.front();Q.pop();
                ans.back().push_back(cur->val);
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
        }
        return ans;
    } 
};