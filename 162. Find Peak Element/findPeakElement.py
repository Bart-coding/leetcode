class Solution:
    def findPeakElement(self, nums: list[int]) -> int:
        if len(nums) == 1:
            return 0
        if len(nums) == 2:
            return nums.index(max(nums))
        if nums[0] > nums[1]:
            return 0
        if nums[-1] > nums[-2]:
            return len(nums) - 1
        left = 1
        right = len(nums) - 2
        while left < right:
            mid = (left + right) // 2
            greater_than_prev = nums[mid] > nums[mid - 1]
            greater_than_next = nums[mid] > nums[mid + 1]
            if greater_than_prev and greater_than_next:
                return mid
            if not greater_than_prev:
                right = mid - 1
            else:
                left = mid + 1
        return left