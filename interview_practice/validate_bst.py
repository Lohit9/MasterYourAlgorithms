# def BST(object):
#     def __init__(self, val):
#         self.left = None
#         self.right = None
#         self.val = val
#
#

def inorder(self, root, output):
    if root is None: return
    inorder(root.left, output)
    output.append(root.val)
    inorder(root.right, output)

def is_BST(self, root):
    output = []
    self.inorder(root, output)
    for i in range(1, len(output)):
        if ouput[i+1] < output[i]:
            return False
    return True
