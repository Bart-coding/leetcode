# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        def findMinNode(node: TreeNode) -> Optional[TreeNode] | TreeNode:
            father = node
            child = node.left
            while child.left is not None:
                father = child
                child = child.left
            return child, father
        def deleteNode_dfs(node: Optional[TreeNode], father: TreeNode, is_left_sided: bool):
            if node is not None:
                if key == node.val:
                    if node.left is None and node.right is None:
                        if is_left_sided:
                            father.left = None
                        else: 
                            father.right = None
                    elif node.left is None:
                        if is_left_sided:
                            father.left = node.right
                        else: 
                            father.right = node.right
                    elif node.right is None:
                        if is_left_sided:
                            father.left = node.left
                        else: 
                            father.right = node.left
                    else:
                        if node.right.left is None:
                            node.val = node.right.val
                            node.right = node.right.right
                        else:
                            successor_node, successor_node_father = findMinNode(node.right)
                            node.val = successor_node.val
                            successor_node_father.left = successor_node.right
                elif key < node.val:
                    deleteNode_dfs(node.left, node, True)
                else:
                    deleteNode_dfs(node.right, node, False)
        pre_root = TreeNode(float('inf'), root)
        deleteNode_dfs(root, pre_root, True)
        return pre_root.left