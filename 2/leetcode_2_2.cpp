#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 步骤
 * 不对齐零，若链表不为空，则用sum(代表每位的和结果)加上，考虑进位
 */
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            ListNode *head = new ListNode(-1);
            ListNode *w = head;
            bool count = false; // 进位标记
            int sum = 0;    // 每个进位相加的结果

            while (l1 != NULL || l2 != NULL) {
                sum = 0;
                if (l1 != NULL) {
                    sum += l1->val;
                    l1 = l1->next;
                }

                if (l2 != NULL) {
                    sum += l2->val;
                    l2 = l2->next;
                }

                if (count) {
                    sum++;
                }
                w->next = new ListNode(sum % 10);
                w = w->next;

                count = sum >= 10 ? true : false;
            }

            if (count) {
                w->next = new ListNode(1);
            }
            return head->next;
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
    ListNode *l1 = new ListNode(2);
    So.insert(l1, 4);
    So.insert(l1, 3);   
  
    ListNode *l2 = new ListNode(5);
    So.insert(l2, 6);
    So.insert(l2, 4);

    ListNode *ret = So.addTwoNumbers(l1, l2);

    while (ret != NULL) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}

void test_case_2(Solution So) {
    ListNode *l1 = new ListNode(1);
    So.insert(l1, 8);
  
    ListNode *l2 = new ListNode(0);

    ListNode *ret = So.addTwoNumbers(l1, l2);

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