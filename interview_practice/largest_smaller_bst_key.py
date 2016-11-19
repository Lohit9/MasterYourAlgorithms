'''
Given a root of a binary search tree and a key x, find the largest key in the tree that is smaller than x.
'''

class Tree(object):
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

def smallerKey(root):
    res = root.val
    while(root != None):
        if root.val > x:
            root = root.left
        else:
            res = root.val
            root = root.right
    return res
