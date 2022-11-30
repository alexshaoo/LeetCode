class Solution:
  def uniqueOccurrences(self, arr: List[int]) -> bool:
    c = Counter(arr)
    v = c.values()
    return len(v) == len(set(v))
    