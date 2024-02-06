var pathSum = function (root, sum) {
    if (!root) return 0;
    function pathSumFromCurrentRoot(currentRoot, missingVal) {
        let currentSum = 0;
        if (currentRoot.val === missingVal) ++currentSum;
        if (currentRoot.left) currentSum += pathSumFromCurrentRoot(currentRoot.left, missingVal - currentRoot.val);
        if (currentRoot.right) currentSum += pathSumFromCurrentRoot(currentRoot.right, missingVal - currentRoot.val);
        return currentSum;
    }
    return pathSumFromCurrentRoot(root, sum) + pathSum(root.left, sum) + pathSum(root.right, sum);
};