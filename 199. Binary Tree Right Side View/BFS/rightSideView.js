var rightSideView = function(root) {
    if (!root) return [];
    let result = [];
    let queue = [root];
    while (queue.length > 0) {
        result.push(queue[0].val);
        let fathersQueueLength = queue.length;
        for (let i = 0; i < fathersQueueLength; ++i) {
            if (queue[0].right) queue.push(queue[0].right);
            if (queue[0].left) queue.push(queue[0].left);
            queue.shift();
        }
    }
    return result;
};