class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> hashStack_s, hashStack_t;
        
        for (int i = s.length()-1; i>=0; --i)
        {
            if (s[i] == '#')
            {
                hashStack_s.push('#');
                s.erase(i, 1);
            }
            else if (!hashStack_s.empty())
            {
                hashStack_s.pop();
                s.erase(i, 1);
            }
        }
        for (int i = t.length()-1; i>=0; --i)
        {
            if (t[i] == '#')
            {
                hashStack_t.push('#');
                t.erase(i, 1);
            }
            else if (!hashStack_t.empty())
            {
                hashStack_t.pop();
                t.erase(i, 1);
            }
        }
        
        return s==t;
    }
};
