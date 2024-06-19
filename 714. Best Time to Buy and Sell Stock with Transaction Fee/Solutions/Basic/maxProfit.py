class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        day_max_profit_no_stock_in_hand = 0
        day_max_profit_stock_in_hand = -prices[0] - fee
        
        for price in prices[1:]:
            day_max_profit_no_stock_in_hand = max(
                day_max_profit_no_stock_in_hand,
                day_max_profit_stock_in_hand + price)
            day_max_profit_stock_in_hand = max(
                day_max_profit_stock_in_hand, 
                day_max_profit_no_stock_in_hand - price - fee)

        return day_max_profit_no_stock_in_hand