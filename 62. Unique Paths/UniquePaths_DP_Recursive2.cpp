class Solution {
public:
    int uniquePathsHelper(int m, int n, vector<vector<int>> &results) {
        if (m == 1 || n == 1)
            results[m][n] = 1;
        if (results[m][n] != 0)
            return results[m][n];
    
        results[m][n] = uniquePathsHelper(m-1, n, results) + uniquePathsHelper(m, n-1, results);
        return results[m][n];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> results(m+1, vector<int> (n+1));
        return uniquePathsHelper(m, n, results);
    }
};
