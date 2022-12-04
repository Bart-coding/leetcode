class Solution {
public:
    bool isValid(string s) {
        std::unordered_set<char> bracketOpenings = {'(','{','['};
        std::stack<char> bracketsStack;
        
        for (char c : s)
        {
            if (bracketOpenings.find(c) != bracketOpenings.end())
                bracketsStack.push(c);
            else
            {
                char bracketOpening;
                if (c == ')')
                    bracketOpening = '(';
                else
                    bracketOpening = (char) (c-2); //ASCII
                
                if (bracketsStack.empty() || bracketsStack.top() != bracketOpening)
                    return false;
                bracketsStack.pop();
            }
        }
        if (!bracketsStack.empty())
            return false;
        return true;
    }
};
