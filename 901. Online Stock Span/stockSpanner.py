class StockSpanner:
    def __init__(self):
        self.days_stack: list[tuple[int, int]] = []
    def next(self, price: int) -> int:
        span = 1
        while self.days_stack and self.days_stack[-1][0] <= price:
            span += self.days_stack.pop()[1]
        self.days_stack.append((price, span))
        return span

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)