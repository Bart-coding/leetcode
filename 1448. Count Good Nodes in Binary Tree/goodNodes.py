# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def goodNodes_dfs(node: TreeNode, good_nodes=0.0, max_ancestor_val=root.val) -> int:
            if node == None:
                return good_nodes
            if node.val >= max_ancestor_val:
                good_nodes += 1.0
                max_ancestor_val = node.val
            return goodNodes_dfs(node.left, good_nodes / 2, max_ancestor_val) + goodNodes_dfs(node.right, good_nodes / 2, max_ancestor_val)
        return int(goodNodes_dfs(root))