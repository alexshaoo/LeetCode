class Solution:
  def closeStrings(self, word1: str, word2: str) -> bool:
    l1 = len(word1)
    l2 = len(word2)
    
    if l1 != l2:
      return False
    
    c1 = Counter(word1)
    c2 = Counter(word2)
    
    v1 = sorted(list(c1.values()))
    v2 = sorted(list(c2.values()))
    
    return set(word1) == set(word2) and v1 == v2