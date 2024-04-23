class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if len(word1) == 0 or len(word2) == 0:
            return len(word1) + len(word2)
        if word1 == word2:
            return 0
        min_dist_table = []
        n = len(word1)
        m = len(word2)
        min_dist_table.append([num for num in range(0, m+1)])
        for i in range(1, n+1):
            min_dist_table.append([])
            min_dist_table[i].append(i)
            for j in range(1, m+1):
                if word1[i-1] == word2[j-1]:
                    min_dist_table[i].append(min_dist_table[i-1][j-1])
                else:
                    min_dist_table[i].append(min(min_dist_table[i-1][j], min_dist_table[i][j-1], min_dist_table[i-1][j-1]) + 1)
        return min_dist_table[n][m]