class Solution:
  def maxProfit(self, prices: List[int]) -> int:
    l = len(prices)
    # buy = [0] * l
    # buy[0] = -prices[0]
    # sell = [0] * l
    # rest = [0] * l
    
    # for i in range(1, l):
    #   buy[i] = max(buy[i-1], sell[i-2] - prices[i-1])
    #   sell[i] = max(sell[i-1], buy[i-1] + prices[i-1])
    # print(buy, sell)

    b = -prices[0]
    s = r = 0
    for p in prices:
      cb = max(b, s-p)
      cs = max(r, b+p)
      b = cb
      s, r = r, cs
    return r