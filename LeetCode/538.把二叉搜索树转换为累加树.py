# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.preNum = 0
        def BST2BAT(nd):
            if not nd:
                return
            BST2BAT(nd.right)
            nd.val += self.preNum
            self.preNum = nd.val
            BST2BAT(nd.left)
        
        BST2BAT(root)
        return root