#include <iostream>
#include <vector>
#include <queue>
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
        TreeNode* trimBST(TreeNode* root, int L, int R) {
           if (root == nullptr) return root;
           if (root->val > R) return trimBST(root->left, L, R);
           if (root->val < L) return trimBST(root->right, L, R); 

           root->left = trimBST(root->left, L, R);
           root->right = trimBST(root->right, L, R);
           return root;
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
                if (leftNum < maxNum && v[leftNum] >= 0 && node->left == NULL) {
                    node->left = new TreeNode(v[leftNum]);
                    QN.push(node->left);
                    Q.push(leftNum);
                }
                
                if (rightNum < maxNum && v[rightNum] >= 0 && node->right == NULL) {
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
    vector<int> x = {1, 0, 2};
    TreeNode *root = nullptr;

    So.insert(root, x);

    int L = 1;
    int R = 2;
    So.trimBST(root, L, R);
    So.inorder(root);  
}

void test_case_2(Solution So) {
    vector<int> x = {3, 0, 4, -1, 2, -1, -1, -1, -1, 1};
    TreeNode *root = nullptr;

    So.insert(root, x);

    int L = 1;
    int R = 3;
    So.trimBST(root, L, R);
    So.inorder(root);
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}