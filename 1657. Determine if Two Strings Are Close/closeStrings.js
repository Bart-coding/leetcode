/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var closeStrings = function(word1, word2) {
    if (word1.length !== word2.length) return false;
    let letters1 = new Set();
    let word1NumsOfOccurencesMap = new Map();
    for (let ch of word1) {
        letters1.add(ch);
        if (!word1NumsOfOccurencesMap.has(ch)) word1NumsOfOccurencesMap.set(ch, 1);
        else word1NumsOfOccurencesMap.set(ch, word1NumsOfOccurencesMap.get(ch) + 1);
    }
    let word2NumsOfOccurencesMap = new Map();
    for (let ch of word2) {
        if (!letters1.has(ch)) return false;
        if (!word2NumsOfOccurencesMap.has(ch)) word2NumsOfOccurencesMap.set(ch, 1);
        else word2NumsOfOccurencesMap.set(ch, word2NumsOfOccurencesMap.get(ch) + 1);
    }
    let word1NumsOfOccurencesArray = Array.from(word1NumsOfOccurencesMap.values());
    let word2NumsOfOccurencesArray = Array.from(word2NumsOfOccurencesMap.values());
    return word1NumsOfOccurencesArray.sort().join() === word2NumsOfOccurencesArray.sort().join();
};