class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:

        merged = []

        if len(word1) >= len(word2):
            for i in range(len(word2)):
                merged.append(word1[i])
                merged.append(word2[i])
            merged.extend(word1[len(word2):])
        else:
            for i in range(len(word1)):
                merged.append(word1[i])
                merged.append(word2[i])
            merged.extend(word2[len(word1):])

        return "".join(merged)