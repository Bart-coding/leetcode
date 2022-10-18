class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> charPairs;
        string usedChars;
        
        if (s.length() == 1)
            return true;
        
        for (int i=0; i<s.length(); ++i)
        {
            if (charPairs.find(s[i]) == charPairs.end()) //!charPair.contains(s[i])
            {
                if (usedChars.find(t[i]) == std::string::npos) //!usedChars.contains(t[i])
                {
                    charPairs[s[i]] = t[i];
                    usedChars += t[i];
                }
                else
                    return false;
            }
                
            else if (charPairs[s[i]] != t[i])
                return false;
        }
        
        return true;
    }
};
