class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        if (nums.size()==1)
            return nums;
        
        for (int i = 1; i<nums.size(); i++)
            nums.at(i) += nums.at(i-1);
        
        return nums;
    }
};
