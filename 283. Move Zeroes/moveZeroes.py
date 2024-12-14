class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        try:
            first_zero_idx = nums.index(0)
        except ValueError:
            return
        
        for i in range(first_zero_idx + 1, len(nums)):
            if nums[i] != 0:
                nums[first_zero_idx] = nums[i]
                nums[i] = 0
                first_zero_idx += 1