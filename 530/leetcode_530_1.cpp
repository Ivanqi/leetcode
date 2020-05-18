#include <iostream>
#include <vector>
#include <algorithm>
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
        // 中序遍历
        void dfs(TreeNode* root, int& prev, int& res) {
            cout << "prev: " << prev << endl;
            if (root == NULL) return;
            dfs(root->left, prev, res);

            if (prev >= 0) res = min(res, root->val - prev);
            prev = root->val;
            cout << "res: " << res << " | prev: " << prev << endl; 
            
            dfs(root->right, prev, res);
        }

        int getMinimumDifference(TreeNode* root) {
            int prev = -1;
            int res = INT_MAX;
            dfs(root, prev, res);
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
    vector<int> v = {1, 3, 2};
    TreeNode* root = NULL;

    for (int i = 0; i < v.size(); i++) {
        So.insert(root, v[i]);
    }
    So.getMinimumDifference(root);
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}
