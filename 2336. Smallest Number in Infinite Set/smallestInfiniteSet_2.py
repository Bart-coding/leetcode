class SmallestInfiniteSet:
    def __init__(self):
        self.inf_set = set(range(1000, 0, -1))

    def popSmallest(self) -> int:
        smallest = min(self.inf_set)
        self.inf_set.remove(smallest)
        return smallest

    def addBack(self, num: int) -> None:
        self.inf_set.add(num)
                
# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)