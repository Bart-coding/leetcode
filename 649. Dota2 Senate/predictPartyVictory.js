/**
 * @param {string} senate
 * @return {string}
 */
var predictPartyVictory = function(senate) {
    let direSenatorsToBan = 0;
    let radiantSenatorsToBan = 0;
    let bannedSenators;
    do {
        bannedSenators = 0;
        let newSenate = "";
        for (let senatorParty of senate) {
            if (senatorParty === 'D') {
                if (direSenatorsToBan > 0) {
                    ++bannedSenators;
                    --direSenatorsToBan;
                }
                else {
                    ++radiantSenatorsToBan;
                    newSenate += 'D';
                }
            }
            else {
                if (radiantSenatorsToBan > 0) {
                    ++bannedSenators;
                    --radiantSenatorsToBan;
                }
                else {
                    ++direSenatorsToBan;
                    newSenate += 'R';
                }
            }
        }
        senate = newSenate;
    } while (bannedSenators > 0);
    return direSenatorsToBan > radiantSenatorsToBan ? "Radiant" : "Dire";
};