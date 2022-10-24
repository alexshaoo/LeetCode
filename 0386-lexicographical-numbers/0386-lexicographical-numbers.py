class Solution:
  def lexicalOrder(self, n: int) -> List[int]:
    out = [1]
    while len(out) < n:
      num = 10*out[-1]
      while num > n:
        num = (num // 10) + 1
        while num % 10 == 0:
          num //= 10
      out.append(num)
    return out
