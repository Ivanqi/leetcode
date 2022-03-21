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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if (headA == nullptr || headB == nullptr) return nullptr;

            unordered_set<ListNode*> visited;
            ListNode *temp = headA;
            while (temp != nullptr) {
                visited.insert(temp);
                temp = headA->next;
            }

            temp = headB;
            while (temp != nullptr) {
                if (visited.count(temp)) {
                    return temp;
                }
                temp = temp->next;
            }

            return nullptr;
        }
};