class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> anagramsIndexes;
        if (s.length() < p.length())
           return anagramsIndexes;
        
        unordered_map<char, int> pLettersMap;
        for (char c : p)
           ++pLettersMap[c];
        
        unordered_map<char, int> foundLettersMap;
        int foundLetters = 0;
        int pLength = p.length();
        for (int i = 0; i < pLength; ++i) //initializing sliding window
        {
            if(pLettersMap.find(s[i]) != pLettersMap.end())
            {
                ++foundLettersMap[s[i]];
                if(foundLettersMap[s[i]] <= pLettersMap[s[i]])
                    ++foundLetters;
            }
        }
        if (foundLetters == pLength)
            anagramsIndexes.push_back(0);
            
        for (int i = pLength; i < s.length(); ++i) //sliding the window
        {
            char letterToRemove = s[i - pLength]; //letter before the window range
            if(foundLettersMap.find(letterToRemove) != foundLettersMap.end())
            {
                --foundLettersMap[letterToRemove];
                if(foundLettersMap[letterToRemove] < pLettersMap[letterToRemove])
                  --foundLetters;
            }
            if(pLettersMap.find(s[i]) != pLettersMap.end()) //new letter in the window range
            {
                ++foundLettersMap[s[i]];
                if(foundLettersMap[s[i]] <= pLettersMap[s[i]])
                    ++foundLetters;
            }
            if (foundLetters == pLength)
                anagramsIndexes.push_back(i - pLength + 1); 
        }
        return anagramsIndexes;   
    }
};
