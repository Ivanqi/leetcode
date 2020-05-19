#include <iostream>
#include <vector>
#include <queue>
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
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;
            if (root == nullptr) return ans;

            stack<TreeNode *> S;
            S.push(root);

            while (!S.empty()) {
                TreeNode *cur = S.top();
                S.pop();

                if (cur != nullptr) {
                    if (cur->right) S.push(cur->right);
                    S.push(cur);
                    S.push(nullptr);
                    if (cur->left) S.push(cur->left);
                } else {
                    ans.push_back(S.top()->val);
                    S.pop();
                }
            }

            return ans;
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
    
    vector<int> v = {1, 0, 2, 0, 0, 3};
    TreeNode *root = NULL;
    So.insert(root, v);
    vector<int> ret = So.inorderTraversal(root);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}