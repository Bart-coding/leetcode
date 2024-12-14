class Solution:
    def isMonotonic(self, nums: list[int]) -> bool:

        if len(nums) == 1:
            return True

        increasing = decreasing = True

        for i in range(len(nums) - 1):

            if nums[i] < nums[i + 1] and decreasing:
                decreasing = False
            elif nums[i] > nums[i + 1] and increasing:
                increasing = False
            
            if not increasing and not decreasing:
                return False

        return True
