#include <map>
class Solution {

public:
    int romanToInt(string s) {
        
        map<char,int> romanSymbolsMap;
        romanSymbolsMap.insert(pair<char,int>('I',1));
        romanSymbolsMap.insert(pair<char,int>('V',5));
        romanSymbolsMap.insert(pair<char,int>('X',10));
        romanSymbolsMap.insert(pair<char,int>('L',50));
        romanSymbolsMap.insert(pair<char,int>('C',100));
        romanSymbolsMap.insert(pair<char,int>('D',500));
        romanSymbolsMap.insert(pair<char,int>('M',1000));
        
        int finalNumber = 0;
        
        int nextSymbol = romanSymbolsMap[s.at(0)];
        
        int i;
        for (i = 0; i<s.length()-1; ++i)
        {
            
            int actualSymbol = nextSymbol;
            nextSymbol = romanSymbolsMap[s.at(i+1)];
            
            if (actualSymbol < nextSymbol)
            {
                finalNumber+= nextSymbol - actualSymbol;
                
                if (i+2<s.length())
                    nextSymbol = romanSymbolsMap[s.at(i+2)];
                i++;
                
                continue; //it 'means' i+=2;
            }
            
            finalNumber+= actualSymbol;
        }
        
        if (i==s.length()-1) //there is an unused symbol
            finalNumber+= nextSymbol;
        
        
        
        return finalNumber;
    }
};
