class Solution:
  def maximum69Number(self, num: int) -> int:
    num = list(str(num))
    for i, digit in enumerate(num):
      if digit == "6":
        num[i] = "9"
        break
    return int("".join(num))
    