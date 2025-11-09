class RandomizedSet:
  def __init__(self):
    self.v2i = {}
    self.i2v = {}
    self.i = 0
    self.s = []

  def insert(self, val: int) -> bool:
    if val in self.v2i: 
      return False
    self.v2i[val] = self.i
    self.i2v[self.i] = val
    self.s.append(self.i)
    self.i += 1
    return True
    

  def remove(self, val: int) -> bool:
    if val not in self.v2i: 
      return False
    idx = self.v2i[val]
    del self.v2i[val]
    del self.i2v[idx]
    self.s.remove(idx)
    return True
    

  def getRandom(self) -> int:
    return self.i2v[random.choice(self.s)]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()