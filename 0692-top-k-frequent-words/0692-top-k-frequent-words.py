class Solution:
  def topKFrequent(self, words: List[str], k: int) -> List[str]:
    freq = {}
    for word in words:
      if word not in freq.keys():
        freq[word] = 1
      else:
        freq[word] += 1
    freq = dict(sorted(freq.items(), key=lambda x: x[0]))
    freq = dict(sorted(freq.items(), key=lambda x: -x[1]))
    return list(freq.keys())[:k]
  