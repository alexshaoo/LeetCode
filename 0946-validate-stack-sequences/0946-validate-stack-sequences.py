class Solution:
  def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
    n = len(pushed)
    lst = []
    i,j = 0,0
    while i < n or j < n:
      if lst and lst[-1] == popped[j]:
        lst = lst[:-1]
        j += 1
      elif i < n:
        lst.append(pushed[i])
        i += 1
      else:
        return False
    return True