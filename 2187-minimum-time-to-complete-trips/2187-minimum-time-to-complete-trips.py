class Solution:
  def minimumTime(self, time: List[int], totalTrips: int) -> int:
    return bisect_left(range(max(time)*totalTrips+1), True, key=lambda x:sum(x//t for t in time) >= totalTrips)