class Solution:
    def average(self, salary: List[int]) -> float:
        
        sum_without_extremes = sum(salary) - min(salary) - max(salary)

        return sum_without_extremes / (len(salary) - 2)
