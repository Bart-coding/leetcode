class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        day_max_profit_no_stock_in_hand = 0
        day_max_profit_stock_in_hand = -prices[0] - fee

        for price in prices[1:-1]:
            buy_profit = (
                day_max_profit_no_stock_in_hand - price
            ) - day_max_profit_stock_in_hand
            if buy_profit > fee:
                day_max_profit_stock_in_hand += buy_profit - fee
            elif buy_profit < 0:
                day_max_profit_no_stock_in_hand = day_max_profit_stock_in_hand + price

        return max(
            day_max_profit_no_stock_in_hand, day_max_profit_stock_in_hand + prices[-1]
        )