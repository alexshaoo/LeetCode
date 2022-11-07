class Solution:
  def maximum69Number(self, num: int) -> int:
    s = str(num)
    l = len(s)
    ind = s.find("6")
    if ind == -1:
      return num
    else:
      return num + 3*(10**(l-ind-1))
    