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
        ListNode* removeElements(ListNode* head, int val) {
            struct ListNode *dummyHeader = new ListNode(0, head);
            ListNode *tmp = dummyHeader;

            while (tmp->next != NULL) {
                if (tmp->next->val == val) {
                    tmp->next = tmp->next->next;
                } else {
                    tmp = tmp->next;
                }
            }

            return dummyHeader->next;
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
    So.insert(l1, 2);
    So.insert(l1, 6);
    So.insert(l1, 3);
    So.insert(l1, 4);
    So.insert(l1, 5);
    So.insert(l1, 6);

    int val = 6;

    ListNode *ret = So.removeElements(l1, val);

    while (ret != NULL) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}

void test_case_2(Solution So) {
    ListNode *l1 = new ListNode(7);
    So.insert(l1, 7);
    So.insert(l1, 7);
    So.insert(l1, 7);

    int val = 7;

    ListNode *ret = So.removeElements(l1, val);

    while (ret != NULL) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}

int main() {

    Solution So;
    test_case_2(So);
    return 0;
}