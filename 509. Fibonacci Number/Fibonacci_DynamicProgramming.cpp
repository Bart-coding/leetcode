class Solution {
public:
    int calculateFib(int n, unordered_map<int,int> &map) {
        if (map.find(n) != map.end()) //n exists in map
            return map[n];
        
        map[n] = calculateFib(n-1, map) + calculateFib(n-2, map);
        return map[n];
    }
    
    int fib(int n) {
        unordered_map<int,int> map;
        map[0] = 0;
        map[1] = 1;
        
        return calculateFib(n, map);
    }
};
