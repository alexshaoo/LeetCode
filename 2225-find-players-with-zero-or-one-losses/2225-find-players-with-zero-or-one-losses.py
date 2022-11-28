class Solution:
  def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
    win = defaultdict(int)
    loss = defaultdict(int)
    players = set()
    for match in matches:
      win[match[0]] += 1
      loss[match[1]] += 1
      players.add(match[0])
      players.add(match[1])
    zero = list(players.difference(loss.keys()))
    one = []
    for player,loss in loss.items():
      if loss == 1:
        one.append(player)
        
    return sorted(zero), sorted(one)
        