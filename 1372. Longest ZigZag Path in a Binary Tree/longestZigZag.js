var longestZigZag = function(root) {
    var longestZigZag2 = function(currentNode, currentLength, isNextLeft) {
        if (!currentNode) return 0;
        ++currentLength;
        return Math.max(
            longestZigZag2(currentNode.left, isNextLeft ? currentLength : 0, false),
            longestZigZag2(currentNode.right, isNextLeft ? 0 : currentLength, true),
            currentLength);
    }
    return Math.max(longestZigZag2(root.left, 0, false), longestZigZag2(root.right, 0, true));
};