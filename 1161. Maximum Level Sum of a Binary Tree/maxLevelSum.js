var maxLevelSum = function(root) {
    let maxSum = root.val;
    let levelWithMaxSum = 1;
    let queue = [];
    if (root.left) queue.push(root.left);
    if (root.right) queue.push(root.right);
    let level = 2;
    while (queue.length > 0) {
        let levelSum = 0;
        let levelWidth = queue.length;
        for (let i = 0; i < levelWidth; i++) {
            let node = queue.shift();
            levelSum += node.val;
            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        }
        if (levelSum > maxSum) {
            maxSum = levelSum;
            levelWithMaxSum = level;
        }
        ++level;
    }
    return levelWithMaxSum;
};