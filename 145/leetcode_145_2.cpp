#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @brief 后序遍历
 * 1. 数据入栈(后进先出)
 * 1. 寻找二叉树的最后一个左子节点
 * 2. 然后寻找左子节点的兄弟节点 - 右子节点
 * 
 */
class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ret;
            if (root == nullptr) return ret;

            stack<TreeNode*> S;
            TreeNode *prev = nullptr;

            while (root != nullptr || !S.empty()) {
                // 寻找树的最左节点
                while (root != nullptr) {
                    S.emplace(root);
                    root = root->left;
                }
                
                root = S.top();
                S.pop();

                if (root->right == nullptr || root->right == prev) {
                    ret.emplace_back(root->val);
                    prev = root;
                    root = nullptr;
                } else {
                    S.emplace(root);
                    root = root->right;
                }
                
            }

            return ret;
        }
};