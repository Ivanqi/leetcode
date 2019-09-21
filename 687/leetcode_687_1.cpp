#include <iostream>
#include <cstdio>
#include <malloc.h>
#include <vector>
#include <algorithm>
#define random(x) (rand()%x)

using namespace std;

/**
 * 最长的路径可能有三种情况:
 *  1. 在左子树内部
 *  2. 在右子树内部
 *  3. 在穿过左子树，根节点，右子树的一条路径中
 * 
 * 设计一个递归函数，返回以该节点为根节点，向下走的最长同值路径
 * 知道这个值以后
 * 就是以某个节点为根节点的最长同值路径
 * 如果该节点的值等于其左子树的值，则最长同值路径要加上左子树的最长同值路径，如果不等，左子树的路径为0
 * 如果该节点的值等于其右子树的值，则最长同值路径要加上右子树的最长同值路径，如果不等，右子树的路径为0
 */
class Solution {
    private:
        typedef struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
        } TreeNode;
        int ans;
    public:
        TreeNode* root;
        void insert(int value) {
            TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
            node->val = value;
            node->left = NULL;
            node->right = NULL;
            if (root == NULL) {             // 判读树是不是空树
                root = node;
            } else {                        // 不是空树
                TreeNode* temp = root;      // 从树根开始
                while (temp != NULL) {
                    if (value < temp->val) {
                        if (temp->left == NULL) {
                            temp->left = node;
                            return;
                        } else {
                            temp = temp->left;
                        }
                    } else {
                        if (temp->right == NULL) {
                            temp->right = node;
                            return ;
                        } else {
                            temp = temp->right;
                        }
                    }
                }
            }
        }
        int calc(TreeNode* root) {

            if (root == NULL) return 0;

            int left = calc(root->left);
            int right = calc(root->right);

            left = (root->left != NULL && root->left->val == root->val) ? left + 1: 0;
            right = (root->right != NULL && root->right->val == root->val) ? right + 1 : 0;

            ans = max(ans, left + right);
            return max(left, right);
        }
        int longestUnivaluePath(TreeNode* root) {
            ans = 0;
            calc(root);
            return ans;
        }
};

void test_case_1(Solution So) {
    vector<int> v;
    v.push_back(5);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(1);
    v.push_back(5);
    for(int i = 0; i < v.size(); i++) {
        So.insert(v[i]);
    }

   cout << "val: "  << So.longestUnivaluePath(So.root) << endl; 
}

void test_case_2(Solution So)
{
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);
    v.push_back(4);
    v.push_back(4);
    v.push_back(5);
    for(int i = 0; i < v.size(); i++) {
        So.insert(v[i]);
    }

   cout << "val: "  << So.longestUnivaluePath(So.root) << endl;  
}

int main () {
    Solution So;
    test_case_2(So);
    return 0;
}