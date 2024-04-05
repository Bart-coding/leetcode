class Solution:
    def combinationSum3(self, k: int, n: int) -> list[list[int]]:
        if (k == 2 and n > 17) or (k == 3 and n > 24) or (k > 3 and n < 10) or (k > 4 and n < 15) or (n > 45):
            return []
        combinations: list[list[int]] = []

        def backtrack(start: int, missing_numbers: int, missing_sum: int, current_combination: list[int]):
            if missing_numbers == 0 and missing_sum == 0: 
                combinations.append(current_combination[:])
            elif missing_numbers > 0 and missing_sum > 0:
                for i in range(start, min(10, missing_sum + 1)):
                    current_combination.append(i)
                    backtrack(i + 1, missing_numbers - 1, missing_sum - i, current_combination)
                    current_combination.pop()

        backtrack(1, k, n, [])
        return combinations