import heapq

class SummaryRanges:
  
  def __init__(self):
    self.intervals=[]

  def addNum(self, val):
    heapq.heappush(self.intervals,[val,val])

  def getIntervals(self):
    merged=[]
    while self.intervals:
      x=heapq.heappop(self.intervals)
      if not merged or x[0]>merged[-1][-1]+1:
        merged.append(x)
      else:
        merged[-1][-1]=max(merged[-1][-1], x[1])
    heapq.heapify(merged)
    self.intervals=merged
    return merged