public class leetcode_19_2 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int len = 0;
        ListNode tmp = head;
        while(tmp != null) {
            len++;
            tmp = tmp.next;
        }
        if (len < n) return null;
        // 因为头结点也有可能被删除，所以增加dummy
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        tmp = dummy;
        while(len - n > 0) {
            tmp = tmp.next;
            len--;
        }
        // tmp 指向要删除的节点前一个节点
        tmp.next = tmp.next.next;
        return dummy.next;
    }
}