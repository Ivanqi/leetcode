#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {

            if (head == nullptr) return head;

            ListNode *cur = head;
            while (cur->next) {
                if (cur->val == cur->next->val) {
                    cur->next = cur->next->next;
                } else {
                    cur = cur->next;
                }
            }
            return head;
        }

        ListNode* insert(ListNode *node, int val)
        {
            if (node == NULL) return node;

            ListNode *p = node;

            while (p->next != NULL) {
                p = p->next;
            }

            p->next = new ListNode(val);

            return node;
        }
};

void test_case_1(Solution So) {
    ListNode *l1 = new ListNode(1);
    So.insert(l1, 1);
    So.insert(l1, 2);


    ListNode *ret = So.deleteDuplicates(l1);

    while (ret != nullptr) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}

void test_case_2(Solution So) {
    ListNode *l1 = new ListNode(1);
    So.insert(l1, 1);
    So.insert(l1, 2);
    So.insert(l1, 3);
    So.insert(l1, 3);


    ListNode *ret = So.deleteDuplicates(l1);

    while (ret != nullptr) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}

int main() {

    Solution So;
    test_case_2(So);
}