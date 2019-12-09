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

class Solution {
    public:
        TreeNode* deleteNode(TreeNode* root, int key) {
            TreeNode* p = root;
            TreeNode* pp = NULL;    // 存储父节点
            // 搜索节点
            while (p != NULL && p->val != key) {
                pp = p;
                if (key > p->val) p = p->right;
                else p = p->left;
            }
            // 没有找到节点
            if (p == NULL) return root;

            // 该节点的左右子节点皆存在
            if (p->left && p->right) {
                TreeNode *minP = p->right;
                TreeNode *minPP = p;
                while (minP->left != NULL) {
                    minPP = minP;
                    minP = minP->left;
                }
                p->val = minP->val;
                p = minP;
                pp = minPP;
            }

            // 存在一个节点或没有子节点
            TreeNode* child;
            if (p->left != NULL) child = p->left;
            else if (p->right != NULL) child = p->right;
            else child = NULL;

            /**
             * 删减具有左右节点是分两步
             * 1. 找到要删除节点的右子树的最小节点，然后将其值copy到要删除节点
             * 2. 删除右子树中的最小节点
             * 3. 将所有实际删除操作放到了最后
             */
            if (pp == NULL) root = child;
            else if (pp->left == p)  pp->left = child;
            else if (pp->right == p) pp->right = child;

            return root;
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

        void inorder(TreeNode* root) {
            if (root != NULL) {
                inorder(root->left);
                cout << root->val << endl;
                inorder(root->right);
            }
        }
};

void test_case_1(Solution So) {
    TreeNode* root = NULL;
    vector<int> v;
    int i, j;
    int deleteNum = 3;
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(2);
    v.push_back(4);
    v.push_back(7);

    for (i = 0; i < v.size(); i++) {
        So.insert(root, v[i]);
    }
    root = So.deleteNode(root, deleteNum);
    So.inorder(root);
}

void test_case_2(Solution So) {
    TreeNode* root = NULL;
    vector<int> v;
    int i, j;
    int deleteNum = 1;
    v.push_back(1);
    v.push_back(2);

    for (i = 0; i < v.size(); i++) {
        So.insert(root, v[i]);
    }
    root = So.deleteNode(root, deleteNum);
    So.inorder(root);
}

int main() {
    Solution So;
    test_case_2(So);
    return 0;
}