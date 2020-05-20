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
 * 时间复杂度:O(n)
 * 空间复杂度:O(n)
 */
class Solution {
    public:
        TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

            if (t1 == nullptr ) {
                return t2;
            }

            stack<pair<TreeNode*, TreeNode*>> S;

            S.push(pair<TreeNode*, TreeNode*>(t1, t2));

            while (!S.empty()) {

                pair<TreeNode*, TreeNode*> cur = S.top();
                S.pop();
                if (cur.first == nullptr || cur.second == nullptr) continue;
                
                cur.first->val += cur.second->val;
                
                if (cur.first->left == nullptr) {
                    cur.first->left = cur.second->left;
                } else {
                    S.push(pair<TreeNode*, TreeNode*>(cur.first->left, cur.second->left));
                }

                if (cur.first->right == nullptr) {
                    cur.first->right = cur.second->right;
                } else {
                    S.push(pair<TreeNode*, TreeNode*>(cur.first->right, cur.second->right));
                }
            }

            return t1;
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
    vector<int> x = {1, 3, 2, 5};
    vector<int> y = {2, 1, 3, 0, 4, 7};
    TreeNode *s = nullptr;
    TreeNode *t = nullptr;

    So.insert(s, x);
    So.insert(t, y);

    TreeNode *ret = So.mergeTrees(s, t);
    So.inorder(ret);
}

int main() {

    Solution So;
    test_case_1(So);
}