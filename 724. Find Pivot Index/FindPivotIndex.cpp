class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int numsSize = nums.size();
        if (numsSize == 1)
            return 0;
        
        int actualLeftSum = 0;
        int actualRightSum = 0;
        
        for (int i=1; i<numsSize; ++i)
            actualRightSum += nums.at(i);
        
        if (actualRightSum == 0)
            return 0;
        
        for (int i=0; i<numsSize-1;)
        {
            actualLeftSum += nums.at(i);
            actualRightSum -= nums.at(++i);
            
            if (actualLeftSum == actualRightSum)
                return i;
        }
        
        return -1;
    }
};
