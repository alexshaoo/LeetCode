class MovieRentingSystem {
 struct ArrayHash {
    template <class T, size_t N>
    size_t operator()(const array<T, N>& a) const {
      size_t h = 0;
      for (auto& x : a) {
        h ^= std::hash<T>()(x) + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
      }
      return h;
    }
  };
  unordered_map<int, set<array<int, 2>>> unrented;
  set<array<int, 3>> rented;
  unordered_map<array<int, 2>, int, ArrayHash> toPrice;
public:
  // movie -> {price, shop} unrented
  // {price, shop, movie} rented
  // {shop, movie} -> price
  MovieRentingSystem(int n, vector<vector<int>>& entries) {
    for (const auto& e : entries) {
      int s = e[0], m = e[1], p = e[2];
      unrented[m].insert({p, s});
      toPrice[{s, m}] = p;
    }
  }
  
  vector<int> search(int movie) {
    vector<int> res;
    int c = 0;
    for (auto it = unrented[movie].begin(); it != unrented[movie].end() && c < 5; ++it, ++c) {
      res.push_back((*it)[1]);
    }
    return res;
  }
  
  void rent(int shop, int movie) {
    int p = toPrice[{shop, movie}];
    unrented[movie].erase({p, shop});
    rented.insert({p, shop, movie});
  }
  
  void drop(int shop, int movie) {
    int p = toPrice[{shop, movie}];
    unrented[movie].insert({p, shop});
    rented.erase({p, shop, movie});
  }
  
  vector<vector<int>> report() {
    vector<vector<int>> res;
    int c = 0;
    for (auto it = rented.begin(); it != rented.end() && c < 5; ++it, ++c) {
      vector<int> sm = {(*it)[1], (*it)[2]};
      res.push_back(sm);
    }
    return res;
  }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */