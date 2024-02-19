/**
 * @param {number[][]} rooms
 * @return {boolean}
 */
var canVisitAllRooms = function (rooms) {
    const keysSet = new Set(rooms[0]);
    let keysStack = [...rooms[0]];
    while (keysStack.length > 0) {
        let key = keysStack.pop();
        rooms[key].forEach(k => {
            if (!keysSet.has(k)) {
                keysSet.add(k);
                keysStack.push(k);
            }
        });
    }
    return keysSet.size === rooms.length
        || !keysSet.has(0) && keysSet.size === rooms.length - 1;
};