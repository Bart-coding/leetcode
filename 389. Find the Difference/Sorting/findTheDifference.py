class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s_sorted_letters = sorted(s)
        t_sorted_letters = sorted(t)
        for i in range(len(s_sorted_letters)):
            if s_sorted_letters[i] != t_sorted_letters[i]:
                return t_sorted_letters[i]
        return t_sorted_letters[-1]