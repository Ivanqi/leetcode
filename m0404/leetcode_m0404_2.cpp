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
        bool isBalance = true;
        int helper(TreeNode* node) {
            if (!isBalance) {
                return 0;
            }

            if (node == NULL) {
                return 0;
            }

            int l = helper(node->left);
            int r = helper(node->right);

            // 判断左右树枝是否平衡，如果不平衡更新剪枝数量
            if (abs(l - r) > 1) {
                isBalance = false;
            }
            return max(l, r) + 1;
        }

        bool isBalanced(TreeNode* root) {
            if (root == NULL)  return true;
        
            helper(root);
            return isBalance;
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
    test_case_2(So);
    return 0;
}