class Router {
  struct Hash {
    size_t operator()(const tuple<int,int,int>& x) const {
        auto [a, b, c] = x;
        return ((size_t)a * 1315423911u) ^ ((size_t)b << 21) ^ ((size_t)c);
    }
  };
  queue<array<int, 3>> q; // {source, destination, timestamp}
  unordered_set<array<int, 3>, Hash> s; // {source, destination, timestamp}
  unordered_map<int, deque<int>> mp; // destination -> timestamp
  int memoryLimit;
public:
  Router(int memoryLimit) {
    this->memoryLimit = memoryLimit;
  }
  
  bool addPacket(int source, int destination, int timestamp) {
    array<int, 3> a = {source, destination, timestamp};
    if (s.find(a) != s.end()) return false;
    if (q.size() == memoryLimit) forwardPacket();
    q.push(a);
    s.insert(a);
    mp[destination].push_back(timestamp);
    return true;
  }
  
  vector<int> forwardPacket() {
    if (q.empty()) return {};
    array<int, 3> a = q.front(); q.pop();
    s.erase(a);
    mp[a[1]].pop_front();
    return vector(a.begin(), a.end());
  }
  
  int getCount(int destination, int startTime, int endTime) {
    auto& dq = mp[destination];
    auto l = lower_bound(dq.begin(), dq.end(), startTime), r = upper_bound(dq.begin(), dq.end(), endTime);
    return r-l;
  }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */