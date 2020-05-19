#include <iostream>
#include <vector>
#include <stack>
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

/**
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
class Solution {
    public:
        TreeNode* convertBST(TreeNode* root) {
           int sum = 0;
           TreeNode *node = root;
           stack<TreeNode *>S;

            while (!S.empty() || node != NULL) {
                while (node != NULL) {
                   S.push(node);
                   node = node->right;
                }
                
                node = S.top();
                S.pop();

                sum += node->val;
                node->val = sum;

                node = node->left;
            }

            return root;
        }

        void insert(TreeNode* &root, int value) {
            if (value == 0) return;
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
    TreeNode *root = NULL;
    vector<int> v = {5, 2, 13};

    for (int i = 0; i < v.size(); i++) {
        So.insert(root, v[i]);
    }

    TreeNode *ret = So.convertBST(root);
    So.inorder(ret);
}

int main() {

    Solution So;
    test_case_1(So);
}