class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        i, j = 0, 0
        while i < len(haystack):
            if haystack[i] == needle[j]:
                if j == len(needle) - 1:
                    return i - j
                j += 1
            elif j != 0:
                i = i - j
                j = 0
            i += 1

        return -1