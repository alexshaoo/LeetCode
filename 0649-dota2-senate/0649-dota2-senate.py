class Solution:
  def predictPartyVictory(self, senate: str) -> str:
    # RRDD -> R
    # DDRR -> D
    # RDRD -> R
    # DRDR -> D
    # RDDR -> R
    # DRRD -> D
    
    l = len(senate)
    
    d = deque()
    r = deque()
    
    for i,s in enumerate(senate):
      if s == "D":
        d.append(i)
      else:
        r.append(i)
        
    while d and r:
      di, ri = d.popleft(), r.popleft()
      if di < ri:
        d.append(di + l)
      else:
        r.append(ri + l)
      # print(d,r)
    return "Radiant" if r else "Dire"
    
    # return "Radiant"