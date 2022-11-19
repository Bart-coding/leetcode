class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoNumsIndices;
        map<int, int> numsMap;
        
        numsMap[nums[0]] = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            int diff = target - nums[i];
            auto it = numsMap.find(diff);
            
            if (it != numsMap.end())
            {
                twoNumsIndices.push_back(i);
                twoNumsIndices.push_back(it->second);
                return twoNumsIndices;
            }
            numsMap[nums[i]] = i;
        }
                            
        return twoNumsIndices;                                          
    }
};
