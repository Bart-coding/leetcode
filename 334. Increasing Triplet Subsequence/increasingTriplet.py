class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        min_1, min_2 = nums[0], float(inf)
        iter_nums = iter(nums)
        next(iter_nums)
        for num in iter_nums:
            if num <= min_1:
                min_1 = num
            elif num <= min_2:
                min_2 = num
            else:
                return True
        return False