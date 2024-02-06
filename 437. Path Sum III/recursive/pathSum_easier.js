var pathSum = function (root, sum) {
    if (!root) return 0;
    function pathSumFromCurrentRoot(currentNode, currentValSum) {
        let currentPathSum = 0;
        currentValSum += currentNode.val;
        if (currentValSum === sum) ++currentPathSum;
        if (currentNode.left) currentPathSum += pathSumFromCurrentRoot(currentNode.left, currentValSum);
        if (currentNode.right) currentPathSum += pathSumFromCurrentRoot(currentNode.right, currentValSum);
        return currentPathSum;
    }
    return pathSumFromCurrentRoot(root, 0) + pathSum(root.left, sum) + pathSum(root.right, sum);
};