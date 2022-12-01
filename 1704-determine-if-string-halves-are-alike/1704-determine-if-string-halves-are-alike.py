class Solution:
  def halvesAreAlike(self, s: str) -> bool:
    l = len(s) // 2
    a = Counter(s[:l])
    b = Counter(s[l:])
    vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
    return sum([a[vowel] for vowel in vowels]) == sum([b[vowel] for vowel in vowels])