#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
 * 时间复杂度: O(n ^ 2)
 * 空间复杂度: O(n)
 */
class Solution {
    public:
        int height(TreeNode *root) {
            if (root == NULL) return 0;

            return max(height(root->left), height(root->right)) + 1;
        }

        bool isBalanced(TreeNode* root) {
            if (root == NULL)  return true;

            int ret = abs(height(root->left) - height(root->right));

            return ret <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }

        void insert(TreeNode* &root, vector<int>& v) {
            
            int maxNum = v.size();
            queue<int> Q;
            Q.push(0);

            if (root == NULL) {
                root = new TreeNode(v[0]);
            }

            queue <TreeNode *> QN;
            TreeNode *node = root;

            QN.push(root);

            while (!QN.empty() && !Q.empty()) {
                node = QN.front();
                QN.pop();

                int cur = Q.front();
                Q.pop();

                int leftNum = 2 * cur + 1;
                int rightNum = 2 * cur + 2;
                if (leftNum < maxNum && v[leftNum] > 0 && node->left == NULL) {
                    node->left = new TreeNode(v[leftNum]);
                    QN.push(node->left);
                    Q.push(leftNum);
                }
                
                if (rightNum < maxNum && v[rightNum] > 0 && node->right == NULL) {
                    node->right = new TreeNode(v[rightNum]);
                    QN.push(node->right);
                    Q.push(rightNum);
                }
            }
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
    vector<int> x = {3, 9, 20, 0, 0, 15, 7};
    TreeNode *root = nullptr;

    So.insert(root, x);

    bool ret = So.isBalanced(root);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> x = {1, 2, 2, 3, 3, 0, 0, 4, 4};
    TreeNode *root = nullptr;

    So.insert(root, x);

    bool ret = So.isBalanced(root);
    cout << "结果为: " << ret << endl;
}


int main() {

    Solution So;
    test_case_2(So);
}