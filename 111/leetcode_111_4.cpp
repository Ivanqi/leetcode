#include <iostream>
#include <stack>
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

// DFS
class Solution {
    private:
        int int_max = 65535;
    public:
        int minDepth(TreeNode* root) {
            if (!root) return 0;
            stack<pair<TreeNode*, int>> stack;
            
            stack.push(make_pair(root, 1));
            int res = int_max;
            while (!stack.empty()) {
                TreeNode* node = stack.top().first;
                int depth = stack.top().second;
                stack.pop();

                if (!node->left && !node->right) res = min(res, depth);

                if (node->left) {
                    stack.push(make_pair(node->left, depth + 1));
                }

                if (node->right) {
                    stack.push(make_pair(node->right, depth + 1));
                }
            }
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