/**
 * @param {number[][]} grid
 * @return {number}
 */
var equalPairs = function(grid) {
    let columns = [];
    for (let num of grid[0]) {
        columns.push(num.toString());
    }
    let n = grid.length;
    for (let i = 1; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            columns[j] += ',' + grid[i][j];
        }
    }
    let rowsMap = new Map();
    for (let row of grid) {
        let rowString = row.join(',');
        if (!rowsMap.has(rowString)) rowsMap.set(rowString, 1);
        else rowsMap.set(rowString, rowsMap.get(rowString) + 1);
    }
    let pairs = 0;
    for (let column of columns) {
        let matchingRowsNum = rowsMap.get(column);
        if (matchingRowsNum !== undefined) {
            pairs += matchingRowsNum;
        }
    }
    return pairs;
};