class Solution:
    def romanToInt(self, s: str) -> int:

        symbols = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}

        int_num = symbols[s[-1]]
        for i in range(len(s) - 2, -1, -1):
            if symbols[s[i]] >= symbols[s[i + 1]]:
                int_num += symbols[s[i]]
            else:
                int_num -= symbols[s[i]]

        return int_num
