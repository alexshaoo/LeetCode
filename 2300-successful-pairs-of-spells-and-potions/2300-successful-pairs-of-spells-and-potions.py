class Solution:
  def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
    quo = sorted([success/x for x in potions])
    return [bisect.bisect_right(quo, spell) for spell in spells]
    