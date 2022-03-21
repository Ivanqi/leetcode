#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        int nodeLength(ListNode *node) {
            int ans = 0;
            if (node == nullptr) return ans;

            while (node != nullptr) {
                ans++;
                node = node->next;
            }
            return ans;
        }

        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if (headA == nullptr || headB == nullptr) return nullptr;

            int headALen = nodeLength(headA);
            int headBLen = nodeLength(headB);
            int len = 0;

            if (headALen > headBLen) {
                len = headBLen;
                while (headALen-- > headBLen) {
                    headA = headA->next;
                }
            } else {
                len = headALen;
                while (headBLen-- > headALen) {
                    headB = headB->next;
                }
            }

            while (len--) {
                if (headA == headB) {
                    return headB;
                }
                headA = headA->next;
                headB = headB->next;
            }

            return nullptr;

            return nullptr;
        }
};