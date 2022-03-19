#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        void helper(TreeNode *root, vector<int>& num) {
            if (root == nullptr) return;
            helper(root->left, num);
            helper(root->right, num);
            num.push_back(root->val);
        }
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ret;
            if (root == nullptr) return ret;

            helper(root, ret);
            return ret;
        }
};