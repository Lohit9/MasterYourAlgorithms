# Given parent pointers

class Tree():
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None


def lowestCommonAns(nodeA, nodeB):
    ansA = set()
    while nodeA :
        ansA.add(nodeA.val)
        nodeA = nodeA.parent

    while nodeB:
        if nodeB in ansA:
            return nodeB.val
        nodeB = nodeB.parent

    return "Error in Code"

    # Runtime is O(logn) because in the first while loop, we traverse the ladder to get to the root node

# O(n) implementation of lowest common ancestor
def lcs(root, p, q):
    if root in (None, p, q): return root
    a1 = lcs(root.left, p, q)
    a2 = lcs(root.right, p, q)
    if a1 and a2: return root
    if not a1: return a2
    if not a2: return a1

def lowestCommonAns2(root, p,q):
    return lca(root, p, q)
