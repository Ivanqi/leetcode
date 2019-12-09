#include <iostream>
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

// BFS
class Solution {
    public:
        int minDepth(TreeNode* root) {
            if (!root) return 0;
            queue<pair<TreeNode*, int>> Q;
            
            Q.push(make_pair(root, 1));
            while (!Q.empty()) {
                TreeNode* node = Q.front().first;
                int depth = Q.front().second;
                Q.pop();

                if (!node->left && !node->right) return depth;

                if (node->left) {
                    Q.push(make_pair(node->left, depth + 1));
                }

                if (node->right) {
                    Q.push(make_pair(node->right, depth + 1));
                }
            }
            return 0;
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