class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> lettersMap;
        for (char c : s)
            lettersMap[c] += 1;
        
        int palindromeLength = 0;
        bool lonelyLetter = false;
        for (auto it : lettersMap)
        {
            int letterQuantity = it.second;
            if ((letterQuantity) %2 == 0)
                palindromeLength += letterQuantity;
            else
            {
                palindromeLength += letterQuantity - 1;
                lonelyLetter = true;
            }
        }
        
        palindromeLength += lonelyLetter;
        return palindromeLength;
    }
};
