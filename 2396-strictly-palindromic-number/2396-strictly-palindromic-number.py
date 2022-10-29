class Solution:
  def isStrictlyPalindromic(self, n: int) -> bool:
    for base in range(2, n-1):
      st = ""
      k = n
      while k > 0:
        st += str(k%base)
        k //= base
      if st != st[::-1]:
        return False
    return True