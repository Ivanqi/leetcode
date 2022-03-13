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
        bool check(TreeNode* u, TreeNode* v) {
            queue<TreeNode*> q;
            q.push(u);
            q.push(v);

            while (!q.empty()) {
                u = q.front();q.pop();
                v = q.front();q.pop();

                if (!u && !v) continue;

                if ((!u || !v) || (u->val != v->val)) return false;

                // 先匹配两个子树的，左子树和右子树
                q.push(u->left);
                q.push(v->right);

                // 再匹配两个子树的，右子树和左子树
                q.push(u->right);
                q.push(v->left);
            }

            return true;
        }

        bool isSymmetric(TreeNode* root) {
            if (root == NULL) return false;
            return check(root->left, root->right);
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
    test_case_1(So);
}