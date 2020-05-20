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
        bool check(TreeNode* s, TreeNode* t) {
            if (s == nullptr && t == nullptr) return true;
            if (s == nullptr || t == nullptr) return false;
            if (s->val != t->val) return false;

            return check(s->left, t->left) && check(s->right, t->right);
        }

        bool dfs(TreeNode* s, TreeNode* t) {
            if (s == nullptr) return false;
            return check(s, t) || dfs(s->left, t) || dfs(s->right, t);
        }

        bool isSubtree(TreeNode* s, TreeNode* t) {
            return dfs(s, t);
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
};

void test_case_1(Solution So) {
    vector<int> x = {3, 4, 5, 1, 2};
    vector<int> y = {4, 1, 2};
    TreeNode *s = nullptr;
    TreeNode *t = nullptr;

    So.insert(s, x);
    So.insert(t, y);

    bool ret = So.isSubtree(s, t);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> x = {3, 4, 5, 1, 2, 0, 0, 0, 0, 6};
    vector<int> y = {4, 1, 2};
    TreeNode *s = nullptr;
    TreeNode *t = nullptr;

    So.insert(s, x);
    So.insert(t, y);

    bool ret = So.isSubtree(s, t);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_1(So);
}