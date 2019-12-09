#include <iostream>
#include <vector>
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
 * 深度优先思想
 *  1. 从根节点开始递归查找
 *  2. 若当前为空说明上一级为是叶子节点，不进行层数增加，返回0
 *  3. 若当前左(右)子树为空，则说明上一级节点只有一个子树，那么为空的停止计数，转向不为空的方向继续计数
 *  4. 若当前左右子树都不为空，分别计算左右子树的深度，选最小返回
 *  5. 循环结束时，所有节点都被遍历，左右子树高度得出，返回左右子树中较小的值为最小高度
 */
class Solution {
    public:
        int minDepth(TreeNode* root) {
            if (root == NULL) return 0;

            int level = 1;
            if (!root->left && !root->right) {
                return level;
            }

            if (!root->left) {
                return level + minDepth(root->right);
            }
            
            if (!root->right) {
                return level + minDepth(root->left);
            }
            
            return level + min(minDepth(root->left), minDepth(root->right));
        }

        void insert(TreeNode* &root, int value) {
            TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
            node->val = value;
            node->left = NULL;
            node->right = NULL;

            if (root == NULL) {
                root = node;
            } else {
                TreeNode* tmp = root;
                while (tmp != NULL) {
                    if (value < tmp->val) {
                        if (tmp->left == NULL) {
                            tmp->left = node;
                            return;
                        } else {
                            tmp = tmp->left;
                        }
                    } else {
                        if (tmp->right == NULL) {
                            tmp->right = node;
                            return;
                        } else {
                            tmp = tmp->right;
                        }
                    }
                }
            }
            return;
        }
};

void test_case_1(Solution So) {
    TreeNode* root = NULL;
    vector<int> v;
    int i, j;
    v.push_back(10);
    v.push_back(9);
    v.push_back(20);
    v.push_back(15);
    v.push_back(21);

    for (i = 0; i < v.size(); i++) {
        So.insert(root, v[i]);
    }

    cout << "最小深度：" << So.minDepth(root) << endl;
}

int main() {
    Solution So;
    test_case_1(So);
    return 0;
}