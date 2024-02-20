/**
 * @param {number} n
 * @param {number[][]} connections
 * @return {number}
 */
var minReorder = function (n, connections) {
    let citiesMap = new Map();
    for (let connection of connections) {
        if (!citiesMap.has(connection[0]))
            citiesMap.set(connection[0], [[connection[1]], []]); //children cities, parent cities
        else
            citiesMap.get(connection[0])[0].push(connection[1]);
        if (!citiesMap.has(connection[1]))
            citiesMap.set(connection[1], [[], [connection[0]]]);
        else
            citiesMap.get(connection[1])[1].push(connection[0]);
    }

    let reorders = 0;
    let traverseCities = (currentCity, nextCity) => {
        if (nextCity === undefined) return;
        for (city of citiesMap.get(nextCity)[0])
            if (city !== currentCity) {
                ++reorders;
                traverseCities(nextCity, city);
            }
        for (city of citiesMap.get(nextCity)[1])
            if (city !== currentCity)
                traverseCities(nextCity, city);
    };
    traverseCities(-1, 0);

    return reorders;
};