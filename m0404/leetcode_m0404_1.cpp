#include <iostream>
#include <vector>
#include <algorithm>
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
        int helper(TreeNode* node) {
            if (node == NULL) {
                return 0;
            }
            int l = helper(node->left);
            int r = helper(node->right);
            return max(l, r) + 1;
        }

        bool isBalanced(TreeNode* root) {
            if (root == NULL)  return true;
        
            return abs(helper(root->left) - helper(root->right)) < 2 && isBalanced(root->left)
            && isBalanced(root->right);
        }

        void insert(TreeNode* &root, vector<int>& v) {
            
            int maxNum = v.size();
            queue<int> Q;
            Q.push(0);

            if (root == NULL) {
                root = createNode(v[0]);
            }
           
            while (!Q.empty()) {
                int cur = Q.front();
                Q.pop();
                TreeNode *nLeft = root;
                TreeNode *nRight = root; 
                int leftNum = 2 * cur + 1;
                if (leftNum <= maxNum && v[leftNum] > 0) {
                    while (nLeft->left != NULL) {
                        nLeft = nLeft->left;
                    }
                    nLeft->left = createNode(v[leftNum]);
                    Q.push(leftNum);
                }

                int rightNum = 2 * cur + 2;
                if (rightNum <= maxNum && v[rightNum] > 0) {
                    while (nRight->right != NULL) {
                        nRight = nRight->right;
                    }
                    nRight->right = createNode(v[rightNum]);
                    Q.push(rightNum);
                }
            }
        }

        TreeNode* createNode(int val)
        {
            TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
            tmp->val = val;
            tmp->left = NULL;
            tmp->right = NULL;
        }
};

void test_case_1(Solution So) {

    vector<int> v = {3, 9, 20, 0, 0, 15, 7};
    TreeNode* root = NULL;
    So.insert(root, v);
    bool ret = So.isBalanced(root);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    TreeNode* root = NULL;
    vector<int> v = {1, 2, 2, 3, 3, 0, 0, 4 , 4};

    So.insert(root, v);

    bool ret = So.isBalanced(root);
    cout << "结果为: " << ret << endl;
}

int main() {
    Solution So;
    test_case_1(So);
    return 0;
}