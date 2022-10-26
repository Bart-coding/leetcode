class Solution {
public:
    int calculateNofWays(int n, unordered_map<int,int> &map) {
        if (map.find(n)!=map.end())
            return map[n];
        map[n] = calculateNofWays(n-2, map) + calculateNofWays(n-1, map);
        return map[n];
    }
    int climbStairs(int n) {
        unordered_map<int,int> map;
        map[1] = 1;
        map[2] = 2;
        
        return calculateNofWays(n, map);
    }
};
