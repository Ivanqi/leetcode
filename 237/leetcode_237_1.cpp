#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *next;
    TreeNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        void deleteNode(ListNode* node) {
            node->val = node->next->val;
            node->next = node->next->next;
        }
};

