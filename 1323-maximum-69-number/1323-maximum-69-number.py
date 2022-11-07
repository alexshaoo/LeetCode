class Solution:
  def maximum69Number (self, num: int) -> int:
    lst = list(str(num))
    lst[str(num).find("6")] = "9"
    return int("".join(lst))