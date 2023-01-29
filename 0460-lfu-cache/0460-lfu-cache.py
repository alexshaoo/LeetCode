class LFUCache:

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        # key => [value, count]
        self.key_val_cnt = {}
        # freq => OrderedDict(key)
        self.freq = collections.defaultdict(collections.OrderedDict)
        # current minimum count
        self.min_count = 1
        
    def _touch(self, key):
        assert(key in self.key_val_cnt)
        cur_count = self.key_val_cnt[key][1]
        self.freq[cur_count].pop(key)
        self.key_val_cnt[key][1] += 1    
        self.freq[cur_count+1][key] = None
        if len(self.freq[self.min_count]) == 0: self.min_count += 1
        
    def _evict(self):
        assert(self.min_count in self.freq)
        # OrderedDict popitem(True) in LIFO order False in FIFO order
        key, val = self.freq[self.min_count].popitem(False)
        del self.key_val_cnt[key]

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.key_val_cnt: return -1
        val = self.key_val_cnt[key][0]
        self._touch(key)
        return val

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if self.capacity == 0: return
        if key in self.key_val_cnt:
            self.key_val_cnt[key][0] = value
            self._touch(key)
        else:
            if len(self.key_val_cnt) == self.capacity:
                self._evict()
            self.key_val_cnt[key] = [value, 1]
            self.freq[1][key] = None
            self.min_count = 1