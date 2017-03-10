# 9.18 - 9.43: 25min :( tooo long!
# Write a function contains_cycle() that takes the first node
# in a singly-linked list and returns a boolean indicating
# whether the list contains a cycle.

def contains_cycle(node):
    fast,slow = node, node
    while fast is not None and fast.next is not None:
        fast = fast.next.next
        slow = slow.next
        if fast == slow:
            return True
    return False

class Solution(object):
    def hasCycle(self, head):
          return contains_cycle(head)
