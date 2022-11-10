class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> results(m+1, vector<int> (n+1));
        
        for (int i = 1; i<m+1; ++i)
            for (int j = 1; j<n+1; ++j)
            {
                if (i == 1 || j == 1)
                    results[i][j] = 1;
                else
                    results[i][j] = results[i-1][j] + results[i][j-1];
            }
        return results[m][n];
    }
};
