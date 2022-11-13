class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewelsInStones = 0;
        for (char s : stones)
            if (jewels.find(s) != string::npos)
                ++jewelsInStones;
                
        return jewelsInStones;
    }
};
