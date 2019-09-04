class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if (head->next == nullptr) 
            return nullptr;
        
        ListNode *slow = head;
        ListNode *fast = head;

        for (int i = 0; i < n; ++i) 
            fast = fast->next;
        if (fast == nullptr) 
            return head->next;
            
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *tmp = slow->next;
        slow->next = tmp->next;

        return head;
    }
};