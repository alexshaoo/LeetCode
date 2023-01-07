class Solution:
  def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
    diff = [g-c for g,c in zip(gas, cost)]
    if sum(diff) < 0: 
      return -1
    tank = 0
    i = 0 
    for ii, d in enumerate(diff):
      tank += d
      if tank < 0: 
        tank = 0
        i = ii+1
    return i
      