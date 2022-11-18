class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoNumsIndices;
        map<int, int> map;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            int diff = target - nums[i];
            auto it = map.find(diff);
            
            if (it != map.end())
            {
                twoNumsIndices.push_back(i);
                twoNumsIndices.push_back(it->second);
                return twoNumsIndices;
            }
            map[nums[i]] = i;
        }
                            
        return twoNumsIndices;                                          
    }
};
