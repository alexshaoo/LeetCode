class Solution:
  def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
    d = collections.defaultdict(int)
    ones1 = []
    ones2 = []
    n = len(img1)
    for i in range(n):
      for j in range(n):
        if img1[i][j] == 1:
          ones1.append((i, j))
        if img2[i][j] == 1:
          ones2.append((i, j))
    ans = 0
    for t1 in ones1:
      for t2 in ones2:
        t3 = (t2[0]-t1[0],t2[1]-t1[1])
        d[t3] += 1
        ans = max(ans, d[t3])
    return ans