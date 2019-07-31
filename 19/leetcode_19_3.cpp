class Solution{
public:
    struct ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode result;
        result.next = head;
        struct ListNode* second = &result;
        while(n > 1) {
            head = head->next;
            n--;
        }

        while(head->next != null) {
            head = head->next;
            second = second->next;
        }
        second->next = second->next->next;
        return result;
    }
}