/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    let rottenOrangesQueue = [];
    let originalFreshOranges = 0;
    for (let i = 0; i < grid.length; ++i) {
        for (let j = 0; j < grid[i].length; ++j) {
            if (grid[i][j] === 1) ++originalFreshOranges;
            else if (grid[i][j] === 2) rottenOrangesQueue.push([i, j]);
        }
    }
    if (originalFreshOranges === 0) return 0;
    if (rottenOrangesQueue.length === 0) return -1;
    
    let newRottenOranges = 0;
    let minutes = -1;
    let makeFreshOrangeRotten = (i, j) => {
        try {
             if (grid[i][j] === 1) {
                grid[i][j] = 2;
                rottenOrangesQueue.push([i, j]);
            }
        } catch(error) {}
    };
    while (rottenOrangesQueue.length > 0) {
        let rottenOrangesQueueLength = rottenOrangesQueue.length;
        for (let i = 0; i < rottenOrangesQueueLength; ++i) {
            let [x, y] = rottenOrangesQueue.shift();
            makeFreshOrangeRotten(x, y - 1);
            makeFreshOrangeRotten(x - 1, y);
            makeFreshOrangeRotten(x, y + 1);
            makeFreshOrangeRotten(x + 1, y);
        }
        newRottenOranges += rottenOrangesQueue.length;
        ++minutes;
    }
    return (newRottenOranges === originalFreshOranges) ? minutes : -1;
};