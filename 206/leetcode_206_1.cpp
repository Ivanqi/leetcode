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
        ListNode* reverseList(ListNode* head) {
            ListNode *newNode = nullptr;
            ListNode *tmp = head;
            ListNode *tmp2 = nullptr;

            while (tmp != nullptr) {
                tmp2 = newNode;
                newNode = new ListNode(tmp->val);
                newNode->next = tmp2;
                tmp = tmp->next;
            }

            return newNode;
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
    So.insert(l1, 3); 
    So.insert(l1, 4);
    So.insert(l1, 5);

    ListNode *ret = So.reverseList(l1);

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