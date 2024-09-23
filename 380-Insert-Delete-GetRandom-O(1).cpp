class RandomizedSet {
private:
    unordered_map<int, int> mp;
    int n;
    mt19937 rng; // good rng
public:
    RandomizedSet() : rng{random_device{}()}, n{0} {};
    
    bool insert(int val) {
        if (mp.count(val) > 0) return false;
        mp[val]++;
        n++;
        return true;
    }
    
    bool remove(int val) {
        if (mp.count(val) > 0) {
            mp.erase(val);
            n--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        uniform_int_distribution<int> dist(0, n-1);
        auto rand = dist(rng);
        auto it = mp.begin();
        advance(it, rand);
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */