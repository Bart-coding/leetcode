class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        unordered_map<char, int> potentialCows;
        
        for (int i = 0; i < secret.length(); ++i)
        {
            if (secret[i] == guess[i])
            {
                ++bulls;
                guess[i] = ' ';
            }
            else
                ++potentialCows[secret[i]];
        }
        for (int i = 0; i < guess.length(); ++i)
        {
            if (potentialCows[guess[i]] > 0)
            {
                ++cows;
                --potentialCows[guess[i]];
            }
        }
        
        ostringstream hint;
        hint<<bulls<<"A"<<cows<<"B";
        return hint.str();
    }
};
