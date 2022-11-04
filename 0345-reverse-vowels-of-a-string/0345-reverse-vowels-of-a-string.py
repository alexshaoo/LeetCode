class Solution:
  def reverseVowels(self, s: str) -> str:
    vowels = ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
    v = []
    for c in s:
      if c in vowels:
        v.append(c)
    ss = ""
    for i, c in enumerate(s):
      if c in vowels:
        ss += v[-1]
        v = v[:-1]
      else:
        ss += c
    return ss
      