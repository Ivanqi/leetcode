#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* helper(vector<int>& nums, int left, int right)
        {
            if (left > right) return nullptr;

            int mid = (left + right + 1) >> 1;
            TreeNode *newNode = new TreeNode(nums[mid]);
            newNode->left = helper(nums, left, mid - 1);
            newNode->right = helper(nums, mid + 1, right);

            return newNode;
        }

        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return helper(nums, 0, nums.size() - 1);
        }

        void showTree(TreeNode *root)
        {
            if (root == nullptr) return;

            queue<TreeNode*> Q;
            Q.push(root);

            while (!Q.empty()) {
                TreeNode *tmp = Q.front();Q.pop();
                if (tmp == nullptr) {
                    break;
                }

                cout << tmp->val << " ";

                if (tmp->left != nullptr) {
                    Q.push(tmp->left);
                }

                if (tmp->right != nullptr) {
                    Q.push(tmp->right);
                }
            }

            cout << endl;
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {-10,-3,0,5,9};

    TreeNode *ret = So.sortedArrayToBST(nums);

    So.showTree(ret);
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}