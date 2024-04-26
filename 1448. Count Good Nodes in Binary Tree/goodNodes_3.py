# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.good_nodes = 0
        def goodNodes_dfs(node: TreeNode, max_ancestor_val: int):
            if node == None:
                return
            if node.val >= max_ancestor_val:
                self.good_nodes += 1
                max_ancestor_val = node.val
            goodNodes_dfs(node.left, max_ancestor_val)
            goodNodes_dfs(node.right, max_ancestor_val)
        goodNodes_dfs(root, root.val)
        return self.good_nodes