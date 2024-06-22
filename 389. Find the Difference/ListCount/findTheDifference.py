class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        t_letters = set(t)
        for letter in t_letters:
            if t.count(letter) > s.count(letter):
                return letter