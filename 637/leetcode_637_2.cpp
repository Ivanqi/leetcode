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
        // 统计每层的节点数，和节点值总和 dfs深度优先，先序遍历，一边遍历一边保存
        void dfs(TreeNode *root, int rank, vector<double>& sum, vector<double>& count) {
            if (root == NULL) return;

            sum[rank] += root->val;
            count[rank] += 1;
            dfs(root->left, rank + 1, sum, count);
            dfs(root->right, rank + 1, sum, count);
        }

        int maxHeight(TreeNode *root) {
            if (root == NULL) return 0;

            return max(maxHeight(root->left), maxHeight(root->right)) + 1;
        }

        vector<double> averageOfLevels(TreeNode* root) {
            if (root == NULL) return {};

            int height = maxHeight(root);
            vector<double> sum(height, 0);
            vector<double> count(height, 0);
            vector<double> res;

            dfs(root, 0, sum, count);

            for(int i = 0;i < height; i++) {
                res.push_back(sum[i] / count[i]);
            }
            return res;
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

    vector<double> ret = So.averageOfLevels(root);
    for (int i = 0; i < ret.size(); i++) {
        cout<< (double)ret[i] << endl;
    }
}

int main() {

    Solution So;
    test_case_1(So);
}