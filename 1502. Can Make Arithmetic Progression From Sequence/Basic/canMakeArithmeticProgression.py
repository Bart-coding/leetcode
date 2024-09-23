class Solution:
    def canMakeArithmeticProgression(self, arr: list[int]) -> bool:

        sorted_arr = sorted(arr)
        d = sorted_arr[0] - sorted_arr[1]

        for i in range(1, len(arr) - 1):
            if sorted_arr[i] - sorted_arr[i + 1] != d:
                return False

        return True