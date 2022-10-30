class Solution {
public:
    int minCostClimbingStairsHelper(vector<int> cost, unordered_map<int,int> &sumOfCosts) {
        int numOfStairs = cost.size();
        if (sumOfCosts.find(numOfStairs) != sumOfCosts.end())
            return sumOfCosts[numOfStairs];
        if (numOfStairs == 1 || numOfStairs == 2)
            return sumOfCosts[numOfStairs];
        
        int costOfLastStair = cost.back();
        
        cost.pop_back();
        int minCostToLastStair = minCostClimbingStairsHelper(cost, sumOfCosts);
        cost.pop_back();
        int minCostToPenultimateStair = minCostClimbingStairsHelper(cost, sumOfCosts);
        
        sumOfCosts[numOfStairs] = min(minCostToLastStair, minCostToPenultimateStair) + costOfLastStair;
        return sumOfCosts[numOfStairs];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0); //top of the stairs
        unordered_map<int,int> sumOfCosts;
        sumOfCosts[1] = cost[0];
        sumOfCosts[2] = cost[1];
        return minCostClimbingStairsHelper(cost, sumOfCosts);
    }
};
