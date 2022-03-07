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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode *preHead = new ListNode(-1);
            ListNode *preNext = preHead;

            while (list1 != nullptr && list2 != nullptr) {
                if (list1->val < list2->val) {
                    preNext->next = list1;
                    list1 = list1->next;
                } else {
                    preNext->next = list2;
                    list2 = list2->next;
                }

                preNext = preNext->next;
            }

            preNext->next = list2 != nullptr ? list2 : list1;

            return preHead->next;
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
    So.insert(l1, 4);
  
    ListNode *l2 = new ListNode(1);
    So.insert(l2, 3);
    So.insert(l2, 4);

    ListNode *ret = So.mergeTwoLists(l1, l2);

    while (ret != NULL) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}

void test_case_2(Solution So) {
    ListNode *l1 = new ListNode();
  
    ListNode *l2 = new ListNode();

    ListNode *ret = So.mergeTwoLists(l1, l2);

    while (ret != NULL) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}

void test_case_3(Solution So) {
    ListNode *l1 = new ListNode();
  
    ListNode *l2 = new ListNode(0);

    ListNode *ret = So.mergeTwoLists(l1, l2);

    while (ret != NULL) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}