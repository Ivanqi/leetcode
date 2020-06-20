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
 * 1. 获取两个链表对应的长度
 * 2. 在较短的链表末尾补零
 * 3. 对齐相加考虑进位
 */
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            int len1 = 1;   //记录l1长度
            int len2 = 1;   //记录l2长度
            ListNode *p = l1;
            ListNode *q = l2;

            while (p->next != NULL) {
                len1++;
                p = p->next;
            }

            while (q->next != NULL) {
                len2++;
                q = q->next;
            }

            if (len1 > len2) {
                for (int i = 0; i < len1 - len2; i++) {
                    q->next = new ListNode(0);
                    q = q->next;
                }
            } else {
                for (int i = 0; i < len2 - len1; i++) {
                    p->next = new ListNode(0);
                    p = p->next;
                }
            }

            p = l1;
            q = l2;

            ListNode *l3 = new ListNode(-1);
            ListNode *w = l3;
            bool count = false; // 记录进位
            int i = 0;  // 记录相加结果

            while (p != NULL && q != NULL) {
                i = count + p->val + q->val;

                w->next = new ListNode(i % 10);
                count = i >= 10 ? true : false;

                w = w->next;
                p = p->next;
                q = q->next;
            }
            // 若最后还有位
            if (count) {
                w->next = new ListNode(1);
                w = w->next;
            }
            return l3->next;
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
    test_case_2(So);
    return 0;
}