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
        vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) return ret;

        stack<TreeNode*> S;
        S.push(root);

        while (!S.empty()) {
            TreeNode *node = S.top();
            S.pop();

            ret.push_back(node->val);

            if (node->right != nullptr) {
                S.push(node->right);
            }

            if (node->left != nullptr) {
                S.push(node->left);
            }
        }

        return ret;
    }
};