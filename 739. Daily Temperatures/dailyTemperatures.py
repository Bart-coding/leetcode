class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer = [0] * len(temperatures)
        days_stack = [0]
        for new_day in range(1, len(temperatures)):
            while days_stack and temperatures[new_day] > temperatures[days_stack[-1]]:
                prev_day = days_stack.pop()
                answer[prev_day] = new_day - prev_day
            days_stack.append(new_day)
        return answer