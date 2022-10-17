class Solution {
public:
    string intToRoman(int num) {
        
        const char romanSymbols[4][2] =
        {
            {'I','V'}, //ones
            {'X','L'}, //tens
            {'C','D'}, //hundreds
            {'M'} //thousands
        };
        
        int i = 0; //to iterate through romanSymbols
        int actualLastDigit;
        string convertedNumber = "";
        while (num!=0)
        {
            actualLastDigit = num%10;
            num = num/10;
            
            if (actualLastDigit != 0)
            {
                if (actualLastDigit <= 3)
                convertedNumber.insert(0,actualLastDigit,romanSymbols[i][0]);
                else if (actualLastDigit == 4)
                {
                    convertedNumber.insert(0,1,romanSymbols[i][1]);
                    convertedNumber.insert(0,1,romanSymbols[i][0]);
                }
                else if (actualLastDigit >= 5 && actualLastDigit < 9)
                {
                    if (actualLastDigit > 5)
                        convertedNumber.insert(0,actualLastDigit-5,romanSymbols[i][0]);
                    convertedNumber.insert(0,1,romanSymbols[i][1]);
                }
                else
                {
                    convertedNumber.insert(0,1,romanSymbols[i+1][0]);
                    convertedNumber.insert(0,1,romanSymbols[i][0]);
                }
            }
            
            ++i;
        }
        
        return convertedNumber;
    }
};
