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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            // 都为空的话，显然是相同的
            if (p == NULL && q == NULL) return true;
            // 一个为空，一个非空，显然不同
            if (p == NULL || q == NULL) return false;
            // 两个非空，但val不一样也不行
            if (p->val != q->val) return false;

            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
    vector<int> x = {1, 2, 3};
    vector<int> y = {1, 2, 3};
    TreeNode *p = nullptr;
    TreeNode *q = nullptr;

    So.insert(p, x);
    So.insert(q, y);

    bool ret = So.isSameTree(p, q);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> x = {1, 2};
    vector<int> y = {1, 0, 2};
    TreeNode *p = nullptr;
    TreeNode *q = nullptr;

    So.insert(p, x);
    So.insert(q, y);

    bool ret = So.isSameTree(p, q);
    cout << "结果为: " << ret << endl;
}

void test_case_3(Solution So) {
    vector<int> x = {1, 2, 1};
    vector<int> y = {1, 1, 2};
    TreeNode *p = nullptr;
    TreeNode *q = nullptr;

    So.insert(p, x);
    So.insert(q, y);

    bool ret = So.isSameTree(p, q);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_3(So);
}