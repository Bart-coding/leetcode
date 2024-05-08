class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        min_1, min_2 = nums[0], float(inf)
        for i in range(1, len(nums)):
            if nums[i] <= min_1:
                min_1 = nums[i]
            elif nums[i] <= min_2:
                min_2 = nums[i]
            else:
                return True
        return False