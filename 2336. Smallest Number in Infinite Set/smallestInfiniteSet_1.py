class SmallestInfiniteSet:
    def __init__(self):
        self.popped_numbers = [0]

    def popSmallest(self) -> int:
        for i in range(len(self.popped_numbers)):
            if i != self.popped_numbers[i]:
                self.popped_numbers.insert(i, i)
                return i
        self.popped_numbers.append(len(self.popped_numbers))
        return self.popped_numbers[-1]

    def addBack(self, num: int) -> None:
        self.popped_numbers = [n for n in self.popped_numbers if n != num]
                

# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)