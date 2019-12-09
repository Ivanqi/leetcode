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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int minDepth(TreeNode* root) {
            if (root == NULL) return 0;

            int leftDepth = minDepth(root->left);
            int rightDepth = minDepth(root->right);

            // 处理只有左子树或者右子树的情况或叶子节点
            if (root->left == NULL || root->right == NULL) {
                return leftDepth + rightDepth + 1;
            }

            // 同时存在左右子树
            return 1 + min(leftDepth, rightDepth);
        }

        void insert(TreeNode* &root, int value) {
            TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
            node->val = value;
            node->left = NULL;
            node->right = NULL;

            if (root == NULL) {
                root = node;
            } else {
                TreeNode* tmp = root;
                while (tmp != NULL) {
                    if (value < tmp->val) {
                        if (tmp->left == NULL) {
                            tmp->left = node;
                            return;
                        } else {
                            tmp = tmp->left;
                        }
                    } else {
                        if (tmp->right == NULL) {
                            tmp->right = node;
                            return;
                        } else {
                            tmp = tmp->right;
                        }
                    }
                }
            }
            return;
        }
};

void test_case_1(Solution So) {
    TreeNode* root = NULL;
    vector<int> v;
    int i, j;
    v.push_back(10);
    v.push_back(9);
    v.push_back(20);
    v.push_back(15);
    v.push_back(21);

    for (i = 0; i < v.size(); i++) {
        So.insert(root, v[i]);
    }

    cout << "最小深度：" << So.minDepth(root) << endl;
}

int main() {
    Solution So;
    test_case_1(So);
    return 0;
}