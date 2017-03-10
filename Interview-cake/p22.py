# def deleteNode(node):
#     if node is None or node.next is None: return None
#     prevNode = None
#     while node.next:
#           tempVal = node.val
#           node.val = node.next.val
#           node.next.val = tempVal
#           prevNode = node
#           node = node.next
#     prevNode.next = None
#     delete node
# Delete a node from a singly-linked list, given only a variable pointing to that node.
#
# 8.55 - 9.07 code time   -> 15 min code time 
# 9.07 - 9.15 check time
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


def deleteNodes(node):
    if node is None or node.next is None: return None
    prevNode = None
    while node.next:
          tempVal = node.val
          node.val = node.next.val
          node.next.val = tempVal
          prevNode = node
          node = node.next
    prevNode.next = None
    # delete node

class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        deleteNodes(node)
