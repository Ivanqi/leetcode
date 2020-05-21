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
        bool check(TreeNode* p, TreeNode* q) {
            // 都为空的话，显然是相同的
            if (p == NULL && q == NULL) return true;
            // 一个为空，一个非空，显然不同
            if (p == NULL || q == NULL) return false;
            // 两个非空，但val不一样也不行
            if (p->val != q->val) return false;
            return true;
        }

        bool isSymmetric(TreeNode* root) {

            if (!check(root, root)) return false;

            queue<TreeNode*>pQ;
            queue<TreeNode*>qQ;

            pQ.push(root);
            qQ.push(root);

            while (!pQ.empty()) {
                TreeNode *pCur = pQ.front(); pQ.pop();
                TreeNode *qCur = qQ.front(); qQ.pop();

                if (!check(pCur, qCur)) return false;

                if (pCur != NULL) {
                    if (!check(pCur->left, qCur->right)) return false;
                    if (pCur != NULL) {
                        pQ.push(pCur->left);
                        qQ.push(qCur->right);
                    }

                    if (!check(pCur->right, qCur->left)) return false;
                    if (qCur != NULL) {
                        pQ.push(pCur->right);
                        qQ.push(qCur->left);
                    }
                }
            }

            return true;
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