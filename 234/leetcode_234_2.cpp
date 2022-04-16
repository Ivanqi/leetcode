#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/**
 * @brief 辅助空间+双指针
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            ListNode *dummyHead = new ListNode(0);
            dummyHead->next = head;
        
            ListNode *cur = dummyHead->next;
            vector<int> ret;

            while (cur != nullptr) {
                ret.push_back(cur->val);
                cur = cur->next;
            }

            int n = ret.size();

            for (int i = 0, j = n - 1; i < j; i++, j--) {
                if (ret[i] != ret[j]) return false;
            }

            return true;
        }
};