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


class Solution {
    public:
        bool check(TreeNode* s, TreeNode* t) {
            if (s == nullptr && t == nullptr) return true;
            if (s == nullptr || t == nullptr) return false;
            if (s->val != t->val) return false;

            return check(s->left, t->right) && check(s->right, t->left);
        }
        
        bool isSymmetric(TreeNode* root) {
            return check(root, root);
        }

        void insert(TreeNode* &root, vector<int>& v) {
            
            int maxNum = v.size();
            queue<int> Q;
            Q.push(0);

            if (root == NULL) {
                root = createNode(v[0]);
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
                    node->left = createNode(v[leftNum]);
                    QN.push(node->left);
                    Q.push(leftNum);
                }
                
                if (rightNum < maxNum && v[rightNum] > 0 && node->right == NULL) {
                    node->right = createNode(v[rightNum]);
                    QN.push(node->right);
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

        void inorder(TreeNode* root) {
            if (root != NULL) {
                cout << root->val << endl;
                inorder(root->left);
                inorder(root->right);
            }
        }
};

void test_case_1(Solution So) {
    vector<int> x = {1, 2, 2, 3, 4, 4, 3};
    TreeNode *root = nullptr;

    So.insert(root, x);

    bool ret = So.isSymmetric(root);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> x = {1, 2, 2, 0, 3, 0, 3};
    TreeNode *root = nullptr;

    So.insert(root, x);

    bool ret = So.isSymmetric(root);
    cout << "结果为: " << ret << endl;
}


int main() {

    Solution So;
    test_case_2(So);
}