class Solution:
  def intToRoman(self, n: int) -> str:
    # d = {500: 'D', 10: 'X', 5: 'V', 1000: 'M', 100: 'C', 1: 'I', 50: 'L'}
    return "M"*(n//1000)+"".join([[[r[0]*d,r[0]+r[1]][d>3],[r[1]+r[0]*(d-5),r[0]+r[2]][d>8]][d>4] for d,r in ((n%1000//100,"CDM"),(n%100//10,"XLC"),(n%10,"IVX"))])