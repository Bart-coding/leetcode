class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0); //top of the stairs
        unordered_map<int, int> sumOfCosts;
        sumOfCosts[0] = cost[0];
        sumOfCosts[1] = cost[1];
        
        int costVecSize = cost.size();
        for (int i = 2; i<costVecSize; ++i)
        {
            sumOfCosts[i] = min(sumOfCosts[i-2], sumOfCosts[i-1]) + cost[i];
        }
        
        return sumOfCosts[costVecSize-1];
    }
};
