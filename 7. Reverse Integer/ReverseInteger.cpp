class Solution {
public:
    int reverse(int x) {
        if (x==0)
            return 0;
        
        bool isXPositive = true;
        if (x<0)
            isXPositive = false;
        
        int reversedX = 0;
        
        while (x!=0)
        {
            if (isXPositive)
            {
                if (reversedX <= INT_MAX/10.0) //is it possible to multiply reversedX by 10
                    reversedX = reversedX*10 + x%10;
                else
                    return 0;
            }
            else
            {
                if (reversedX >= INT_MIN/10.0) //is it possible to multiply reversedX by 10
                    reversedX = reversedX*10 + x%10;
                else
                    return 0;
            }
            
            x = x/10;
        }
        
        return reversedX;
    }
};
