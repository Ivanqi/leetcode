#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
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
        void bfs(TreeNode* root, int& prev, int& res) {
            if (root == NULL) return;
            bfs(root->left, prev, res);

            if (prev >= 0) res = min(res, root->val - prev);
            prev = root->val;

            bfs(root->right, prev, res);
        }

        int minDiffInBST(TreeNode* root) {

            int prev = -1;
            int res = INT_MAX;
            bfs(root, prev, res);

            return res;
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
};


void test_case_1(Solution So) {
    vector<int> v = {4, 2, 6, 1, 3};
    TreeNode *root = NULL;
    
    for (int i = 0; i < v.size(); i++) {
        So.insert(root, v[i]);
    }

    int res = So.minDiffInBST(root);
    cout << "结果为: " << res << endl;
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}