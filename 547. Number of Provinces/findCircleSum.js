/**
 * @param {number[][]} isConnected
 * @return {number}
 */
var findCircleNum = function (isConnected) {
    if (isConnected.length === 1) return 1;
    const visitedCities = new Set();
    let provinces = 0;
    let traverseProvince = (currentCity) => {
        visitedCities.add(currentCity);
        for (let nextCity = 0; nextCity < isConnected.length; ++nextCity) {
            if (!visitedCities.has(nextCity) && isConnected[currentCity][nextCity] === 1)
                traverseProvince(nextCity);
        }
    };
    for (let nextStartingCity = 0; nextStartingCity < isConnected.length; ++nextStartingCity) {
        if (!visitedCities.has(nextStartingCity)) {
            ++provinces;
            traverseProvince(nextStartingCity);
        }
    }
    return provinces;
};