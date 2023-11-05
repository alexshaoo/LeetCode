class Solution:
  def getWinner(self, arr: List[int], k: int) -> int:
    cm = arr[0]
    c = 0
    for num in arr[1:]:
      if num > cm:
        c = 1
        cm = num
      else:
        c += 1
      if c == k:
        return cm
    return cm

