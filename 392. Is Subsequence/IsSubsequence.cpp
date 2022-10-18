class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLength = s.length();
        int tLength = t.length();
        if (sLength == 0)
            return true;
        if (sLength>tLength)
            return false;
        
        int i = 0;
        for (int j=0; j<tLength; ++j)
        {
            if (t[j]==s[i])
                ++i;
            if (i == sLength)
                return true;
            if (sLength-i > tLength-j)
                return false;
        }
        
        return false;
    }
};
