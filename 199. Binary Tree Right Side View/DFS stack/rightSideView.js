var rightSideView = function(root) {
    if (!root) return [];
    let result = [];
    let stack = [[root, 1]];
    while (stack.length > 0) {
        let [node, level] = stack.pop();
        if (node) {
            if (level > result.length) result.push(node.val);
            stack.push([node.left, level + 1]);
            stack.push([node.right, level + 1]);
        }
    }
    return result;
};