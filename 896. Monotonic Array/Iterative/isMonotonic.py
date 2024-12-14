class Solution:
    def isMonotonic(self, nums: list[int]) -> bool:

        if len(nums) == 1:
            return True

        i = 0
        while i < len(nums) - 1 and nums[i] == nums[i + 1]:
            i += 1
        if i == len(nums) - 1:
            return True

        if nums[i] < nums[i + 1]:
            while i < len(nums) - 1:
                if nums[i] > nums[i + 1]:
                    return False
                i += 1
        else:
            while i < len(nums) - 1:
                if nums[i] < nums[i + 1]:
                    return False
                i += 1

        return True
