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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        bool hasPathSum(TreeNode* root, int sum) {
            if (root == nullptr) return false;

            queue<TreeNode*> Q;
            queue<int> Qval;

            Q.push(root);
            Qval.push(root->val);

            while (!Q.empty()) {
                TreeNode *tmp = Q.front(); Q.pop();
                int tmpVal = Qval.front(); Qval.pop();

                if (tmp->left == nullptr && tmp->right == nullptr) {
                    if (tmpVal == sum) {
                        return true;
                    }
                    continue;
                }

                if (tmp->left != nullptr) {
                    Q.push(tmp->left);
                    Qval.push(tmp->left->val + tmpVal);
                }

                if (tmp->right != nullptr) {
                    Q.push(tmp->right);
                    Qval.push(tmp->right->val + tmpVal);
                }
            }

            return false;
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

        void inorder(TreeNode* root) {
            if (root != NULL) {
                cout << root->val << endl;
                inorder(root->left);
                inorder(root->right);
            }
        }
};

void test_case_1(Solution So) {
    TreeNode* root = NULL;
    vector<int> v;
    int i, j;
    v.push_back(5);
    v.push_back(4);
    v.push_back(8);
    v.push_back(11);
    v.push_back(13);
    v.push_back(4);
    v.push_back(7);
    v.push_back(2);
    v.push_back(1);

    for (i = 0; i < v.size(); i++) {
        So.insert(root, v[i]);
    }

    cout << "结果: " << So.hasPathSum(root, 32) << endl;
}

int main() {
    Solution So;
    test_case_1(So);
    return 0;
}