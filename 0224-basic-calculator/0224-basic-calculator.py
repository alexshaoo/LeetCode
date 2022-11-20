class Solution:
  def calculate(self, s: str) -> int:
    res, num, sign, stacc = 0, 0, 1, []
    for ss in s:
      if ss.isdigit():
        num = 10*num + int(ss)
      elif ss in ('-', '+'):
        res += sign*num
        num = 0
        sign = -1 if ss == '-' else 1
      elif ss == '(':
        stacc.append(res)
        stacc.append(sign)
        sign, res = 1, 0
      elif ss == ')':
        res += sign*num
        res *= stacc.pop()
        res += stacc.pop()
        num = 0
    return res + num*sign
      