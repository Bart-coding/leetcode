class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            if (prefix.empty())
                return prefix;
            int j = 0;
            int handledStringSize = strs[i].size();
            while (j < prefix.length())
            {
                if (j == handledStringSize || strs[i][j] != prefix[j])
                {
                    prefix = prefix.substr(0, j);
                    break;
                }
                ++j;
            }
        }
        return prefix; 
    }
};
