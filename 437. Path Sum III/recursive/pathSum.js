var pathSum = function (root, sum) {
    if (!root) return 0;
    function pathSumFromCurrentRoot(currentNode, missingVal) {
        let currentSum = 0;
        if (currentNode.val === missingVal) ++currentSum;
        if (currentNode.left) currentSum += pathSumFromCurrentRoot(currentNode.left, missingVal - currentNode.val);
        if (currentNode.right) currentSum += pathSumFromCurrentRoot(currentNode.right, missingVal - currentNode.val);
        return currentSum;
    }
    return pathSumFromCurrentRoot(root, sum) + pathSum(root.left, sum) + pathSum(root.right, sum);
};