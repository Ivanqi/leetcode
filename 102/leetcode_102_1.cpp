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
        vector<vector<int>> ans;
        vector<vector<int>> levelOrder(TreeNode* root) {
            helper(root, 0);
            return ans;
        }

        void helper(TreeNode* root, int level) {
            if (!root) return;
            if (level >= ans.size()) ans.push_back(vector<int>());
            ans[level].push_back(root->val);
            helper(root->left, level + 1);
            helper(root->right, level + 1);
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
                inorder(root->left);
                cout << root->val << endl;
                inorder(root->right);
            }
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

    cout << "[\n";
    vector<vector<int>> ret = So.levelOrder(root);
    for (i = 0; i < ret.size(); i++) {
        vector<int> tmp = ret[i];
        cout << "\t[";
        for (j = 0; j < tmp.size(); j++) {
            cout << tmp[j];
            if (j < tmp.size() - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
    cout << "]" << endl;
}

int main() {
    Solution So;
    test_case_1(So);
    return 0;
}