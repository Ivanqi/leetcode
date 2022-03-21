#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        /*
            [4,1,8,4,5]
            [5,6,1,8,4,5]
        */
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if (headA == nullptr || headB == nullptr) return nullptr;

            ListNode *pA = headA, *pB = headB;
            while (pA != pB) {
                pA = pA == nullptr ? headB : pA->next;
                pB = pB == nullptr ? headA : pB->next;
            }

            return pA;
        }
};