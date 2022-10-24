class Solution {
public:
    int search(vector<int>& nums, int target) {
        int numsSize = nums.size();
        int left = 0;
        int right = numsSize-1;
        int middle;
        
        do
        {
            middle = (left+right)/2;
            int num = nums[middle];
            
            if (target == num)
                return middle;
            if (target > num)
                left = middle+1;
            else if (target < num)
                right = middle-1;
            
        } while (left<=right);
        
        return -1;
    }
};
