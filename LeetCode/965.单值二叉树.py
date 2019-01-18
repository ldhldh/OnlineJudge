# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isUnivalTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        d = {}
        def preOrder(nd):
            if not nd:
                return
            d[nd.val] = d.get(nd.val, 0) + 1
            if len(d) > 1:
                return
            preOrder(nd.left)
            preOrder(nd.right)

        preOrder(root)
        return len(d) < 2