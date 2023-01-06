class Solution:
  def maxIceCream(self, costs: List[int], coins: int) -> int:
    return sum(1 for ice in sorted(costs) if (coins:= coins-ice) >= 0)