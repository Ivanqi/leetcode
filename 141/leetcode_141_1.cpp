#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if (head == NULL || head->next == NULL) return false;

            ListNode *slow = head;
            ListNode *fast = head->next;

            while (slow != fast) {
                if (fast == NULL || fast->next == NULL) return false;

                slow = slow->next;
                fast = fast->next->next;
            }

            return true;
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
    So.insert(l1, 2);
    So.insert(l1, 0); 
    So.insert(l1, -4);
  

    bool ret = So.hasCycle(l1);

   cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}