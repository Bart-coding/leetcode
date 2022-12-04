class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char,char> brackets = {{'(',')'},{'{','}'},{'[',']'}};
        std::stack<char> bracketsStack;
        
        for (char c : s)
        {
            if (brackets.find(c) != brackets.end())
                bracketsStack.push(brackets[c]);
            else
            {
                if (bracketsStack.empty() || c != bracketsStack.top())
                    return false;
                bracketsStack.pop();
            }
        }
        if (!bracketsStack.empty())
            return false;
        return true;
    }
};
