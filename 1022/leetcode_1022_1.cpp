#include <iostream>
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
        int total_sum = 0;
        void dfs(TreeNode *node, int num) {
            if (node == nullptr) {
                return;
            }

            num = (num << 1) + node->val;
            if (node->left == nullptr && node->right == nullptr) {
                total_sum += num;
                return ;
            }
            dfs(node->left, num);
            dfs(node->right, num);
        }

        int sumRootToLeaf(TreeNode* root) {
            total_sum = 0;
            dfs(root, 0);
            return total_sum;
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

                if (leftNum < maxNum && node->left == NULL) {
                    node->left = createNode(v[leftNum]);
                    QN.push(node->left);
                    Q.push(leftNum);
                }
                
                if (rightNum < maxNum && node->right == NULL) {
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
    
    vector<int> v = {1, 0, 1, 0, 1, 0, 1};
    TreeNode *root = NULL;
    So.insert(root, v);
    int ret = So.sumRootToLeaf(root);
    cout << "结果为: " << ret << endl;;
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}