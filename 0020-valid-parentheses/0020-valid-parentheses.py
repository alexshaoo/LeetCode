class Solution:
  def isValid(self, s: str) -> bool:
    opening = ["(", "{", "["]
    closing = [")", "}", "]"]
    pairs = dict(zip(closing, opening))
    stack = []
    for paren in s: 
      if paren in opening: 
        stack.append(paren)
      if paren in closing: 
        if not stack or stack.pop() != pairs[paren]: 
          return False
    return len(stack) == 0