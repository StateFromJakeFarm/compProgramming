# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.max = 0

    def visit(self, node, d, l):
        if node is None:
            return

        self.max = max(self.max, l)
        if d == '':
            # Root
            self.visit(node.left, 'l', 1)
            self.visit(node.right, 'r', 1)
        if d == 'l':
            self.visit(node.left, 'l', 1)
            self.visit(node.right, 'r', l+1)
        elif d == 'r':
            self.visit(node.left, 'l', l+1)
            self.visit(node.right, 'r', 1)


    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.visit(root, '', 0)

        return self.max
