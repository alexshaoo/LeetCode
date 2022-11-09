class StockSpanner:

  def __init__(self):
    self.s = []

  def next(self, price: int) -> int:
    if len(self.s) == 0 or price < self.s[-1][0]:
      self.s.append([price, 1])
      return 1
    n = 1
    print(self.s[-1][0])
    while self.s and price >= self.s[-1][0]:
      n += self.s[-1][1]
      self.s.pop()
    self.s.append([price, n])
    return n


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)