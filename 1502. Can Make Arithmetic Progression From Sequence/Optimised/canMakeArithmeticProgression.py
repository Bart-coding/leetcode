class Solution:
    def canMakeArithmeticProgression(self, arr: list[int]) -> bool:

        d = (max(arr) - min(arr)) / (len(arr) - 1)
        if d == 0:
            return True
        if not d.is_integer():
            return False

        if len(arr) != len(set(arr)):
            return False

        min_num = min(arr)

        for num in arr:
            if (num - min_num) % d != 0:
                return False

        return True