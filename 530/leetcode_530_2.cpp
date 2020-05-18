#include <iostream>
#include <vector>
#include <deque>
#include <limits.h>
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
        // bfs
        int getMinimumDifference(TreeNode* root) {
            int ans = INT_MAX;
            deque<TreeNode*> d;
            d.emplace_back(root);

            vector<int> vec;

            while (!d.empty()) {
                root =  d.front();
                d.pop_front();
                vec.emplace_back(root->val);

                if (root->left != nullptr) d.emplace_back(root->left);
                if (root->right != nullptr) d.emplace_back(root->right);
            }

            sort(vec.begin(), vec.end());

            for (size_t i = 0; i < vec.size() - 1; ++i) {
                cout << vec[i] << endl;
                ans = min(ans, abs(vec[i + 1] - vec[i]));
            }
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
};

void test_case_1(Solution So) {
    vector<int> v = {1, 3, 2};
    TreeNode* root = NULL;

    for (int i = 0; i < v.size(); i++) {
        So.insert(root, v[i]);
    }
    
    int ret = So.getMinimumDifference(root);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}