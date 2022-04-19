#include <iostream>
#include <vector>
#include <queue>
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
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> paths;
            if (root == nullptr) {
                return paths;
            }

            queue<TreeNode*> NodeQ;
            queue<string> pathQ;

            pathQ.push(to_string(root->val));
            NodeQ.push(root);

            while (!NodeQ.empty()) {
                TreeNode *node = NodeQ.front();
                string path = pathQ.front();
                NodeQ.pop();
                pathQ.pop();

                if (node->left == nullptr && node->right == nullptr) {
                    paths.push_back(path);
                } else {
                    if (node->left != nullptr) {
                        NodeQ.push(node->left);
                        pathQ.push(path + "->" + to_string(node->left->val));
                    }

                    if (node->right != nullptr) {
                        NodeQ.push(node->right);
                        pathQ.push(path + "->" + to_string(node->right->val));
                    }
                }
            }

            return paths;
        }
};
