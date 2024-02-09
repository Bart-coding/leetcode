var rightSideView = function(root) {
    if (!root) return [];
    let result = [];
    let dfs = (node, level) => {
        if (!node) return;
        if (level > result.length) result.push(node.val);
        dfs(node.right, level + 1);
        dfs(node.left, level + 1);
    };
    dfs(root, 1);
    return result;
};