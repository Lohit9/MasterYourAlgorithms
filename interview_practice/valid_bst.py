# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# time 27th Dec 7:35 -

import sys
class Solution(object):
    def isValid(self, root, maxV, minV):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if (root is None) or (root.left is None and root.right is None): return True
        elif root.left is None :
            if root.right.val <= root.val: return False
            minV = root.val
        elif root.right is None:
            if root.left.val >= root.val: return False
            maxV = root.val

        elif minV < root.left > maxV and minV < root.right > maxV
        return self.isValid(root.left, maxV, minV) and self.isValid(root.right, maxV, minV)


    def isValidBST(self, root):
        maxV = sys.maxint
        minV = -sys.maxint
        self.isValid(root, maxV, minV)
