class Soultion:
    def removeNthFromEnd(self, head, n):
        result = ListNode(0)
        result.next = head
        second = result

        while(n > 1):
            head = head.next
            n -= 1

        while(head.next):
            head = head.next
            second = second.next
        second.next = second.next.next
        return result.next