var lowestCommonAncestor = function(root, p, q) {
    if (root === null) return null;
    if (root.val === p.val || root.val === q.val) return root;
    let lcaLeft = lowestCommonAncestor(root.left, p, q);
    let lcaRight = lowestCommonAncestor(root.right, p, q);
    if (lcaLeft && lcaRight) return root;
    return lcaLeft || lcaRight;
};