class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        
        unordered_map<int,int> map;
        map[1] = 1;
        map[2] = 2;
        
        for (int i = 3; i<=n; ++i)
        {
            map[i] = map[i-2] + map[i-1];
        }
        
        return map[n];
    }
};
