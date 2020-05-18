#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            queue<TreeNode*> Q;
            vector<vector<int>> ans;
            if(root == nullptr) return ans;
            if (root) Q.push(root);
            vector<int> mid;

            while (!Q.empty()) {
                int size = Q.size();
                for (int i = 0; i < size; i++) {
                    TreeNode *cur = Q.front();
                    mid.push_back(cur->val);
                    Q.pop();
                    if (cur->left) Q.push(cur->left);
                    if (cur->right) Q.push(cur->right);
                }
                ans.push_back(mid);
                mid.clear();
            }
            reverse(ans.begin(),ans.end());
            return ans;
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
    TreeNode* root = NULL;
    vector<int> v = {3, 9, 20, 15, 7};

    for (int i = 0; i < v.size(); i++) {
        So.insert(root, v[i]);
    }


    cout << "[\n";
    vector<vector<int>> ret = So.levelOrderBottom(root);
    for (int i = 0; i < ret.size(); i++) {
        vector<int> tmp = ret[i];
        cout << "\t[";
        for (int j = 0; j < tmp.size(); j++) {
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