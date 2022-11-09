class StockSpanner:

  def __init__(self):
    self.s = []

  def next(self, price: int) -> int:
    n = 1
    while self.s and price >= self.s[-1][0]:
      n += self.s.pop()[1]
    self.s.append([price, n])
    return n


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)