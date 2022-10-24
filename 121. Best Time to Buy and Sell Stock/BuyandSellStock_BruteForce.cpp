class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 0; i<prices.size(); ++i)
        {
            int buyPrice = prices[i];
            
            for (int j=i+1; j<prices.size(); ++j)
            {
                int sellPrice = prices[j];
                if (sellPrice > buyPrice)
                {
                    int profit = sellPrice - buyPrice;
                
                    if (profit > maxProfit)
                    maxProfit = profit;
                }
            }
        }
        
        return maxProfit;
    }
};
