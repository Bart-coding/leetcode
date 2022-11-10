class Solution {
public:
    int uniquePathsHelper(int m, int n, int** results) {
        if (m == 1 || n == 1)
            results[m][n] = 1;
        if (results[m][n] != 0)
            return results[m][n];
    
        results[m][n] = uniquePathsHelper(m-1, n, results) + uniquePathsHelper(m, n-1, results);
        return results[m][n];
    }
    int uniquePaths(int m, int n) {
        int** results;
        results = new int* [m+1];
        for (int i = 0; i<m+1; ++i)
            results[i] = new int[n+1]();
        
        int uniquePaths = uniquePathsHelper(m, n, results);
        
        for (int i = 0; i<m; ++i)
            delete[] results[i];
        delete[] results;
        
        return uniquePaths;
    }
};
