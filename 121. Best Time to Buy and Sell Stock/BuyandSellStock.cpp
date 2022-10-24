class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)
            return 0;
        
        int maxGlobalProfit = 0;
        int localMin = prices[0];
        int localMax = 0;
        
        for (int i = 1; i<prices.size(); ++i)
        {
            int dayPrice = prices[i];
            if (dayPrice < localMin)
            {
                localMin = dayPrice;
                localMax = 0;
            }
            else if (dayPrice > localMax)
            {
                localMax = dayPrice;
                int maxLocalProfit = localMax - localMin;
                if (maxLocalProfit > maxGlobalProfit)
                    maxGlobalProfit = maxLocalProfit;
            }
        }
        
        return maxGlobalProfit;
    }
};
