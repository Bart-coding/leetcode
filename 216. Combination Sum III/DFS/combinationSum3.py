class Solution:
    def combinationSum3(self, k: int, n: int) -> list[list[int]]:
        if (k == 2 and n > 17) or (k == 3 and n > 24) or (k > 3 and n < 10) or (k > 4 and n < 15) or (n > 45):
            return []
        combinations = set()
        def dfs(current_sum: int, current_nums_quantity: int, current_combination: list[int]):
            if current_nums_quantity == k - 1:
                for i in range(1, 10):
                    if i not in current_combination and current_sum + i == n:
                        new_combination = current_combination[:]
                        new_combination.append(i)
                        new_combination.sort()
                        combinations.add(tuple(new_combination))
            else:
                for i in range(1, 10):
                    if i not in current_combination and current_sum + i < n:
                        new_combination = current_combination[:]
                        new_combination.append(i)
                        dfs(current_sum + i, current_nums_quantity + 1, new_combination)
        dfs(0, 0, [])
        return [list(c) for c in combinations]