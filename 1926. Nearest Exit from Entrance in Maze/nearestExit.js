/**
 * @param {character[][]} maze
 * @param {number[]} entrance
 * @return {number}
 */
var nearestExit = function(maze, entrance) {
    let queue = [];
    let visitedCells = new Set([entrance.join(',')]);

    let checkCell = (i, j) => {
        let cellString = i.toString() + ',' + j;
        if (!visitedCells.has(cellString) && maze[i][j] !== '+') {
            visitedCells.add(cellString);
            return true;
        }
        visitedCells.add(cellString);
        return false;
    }
    let populateQueue = (i, j) => {
        if (maze[i] && maze[i][j] && checkCell(i, j)) queue.push([i, j]);
    }
    populateQueue(entrance[0], entrance[1] - 1);
    populateQueue(entrance[0] + 1, entrance[1]);
    populateQueue(entrance[0], entrance[1] + 1);
    populateQueue(entrance[0] - 1, entrance[1]);

    let steps = 1;
    while (queue.length) {
        let queueLength = queue.length;
        for (let i = 0; i < queueLength; ++i) {
            let cell = queue.shift();
            if (cell[0] === 0 || cell[0] === maze.length - 1 || cell[1] === 0 || cell[1] === maze[0].length - 1)
                return steps;
            if (checkCell(cell[0], cell[1] - 1)) queue.push([cell[0], cell[1] - 1]);
            if (checkCell(cell[0] + 1, cell[1])) queue.push([cell[0] + 1, cell[1]]);
            if (checkCell(cell[0], cell[1] + 1)) queue.push([cell[0], cell[1] + 1]);
            if (checkCell(cell[0] - 1, cell[1])) queue.push([cell[0] - 1, cell[1]]);
        }
        ++steps;
    }
    return -1;
};