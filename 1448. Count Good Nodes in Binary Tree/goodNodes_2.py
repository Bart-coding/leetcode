# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def goodNodes_dfs(node: TreeNode, max_ancestor_val=root.val) -> int:
            if node == None:
                return 0
            if node.val >= max_ancestor_val:
                return goodNodes_dfs(node.left, node.val) + goodNodes_dfs(node.right, node.val) + 1
            return goodNodes_dfs(node.left, max_ancestor_val) + goodNodes_dfs(node.right, max_ancestor_val)
        return goodNodes_dfs(root)