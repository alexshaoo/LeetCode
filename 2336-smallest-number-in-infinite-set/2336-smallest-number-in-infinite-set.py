class SmallestInfiniteSet:

    def __init__(self):
        self.s = set(range(1, 1001))

    def popSmallest(self) -> int:
        n = min(self.s)
        self.s.remove(n)
        return n

    def addBack(self, num: int) -> None:
        self.s.add(num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)