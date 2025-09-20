class Router {
  queue<vector<int>> q; // {source, destination, timestamp}
  set<vector<int>> s; // {source, destination, timestamp}
  unordered_map<int, deque<int>> mp; // destination -> timestamp
  int memoryLimit;
public:
  Router(int memoryLimit) {
    this->memoryLimit = memoryLimit;
  }
  
  bool addPacket(int source, int destination, int timestamp) {
    vector<int> v = {source, destination, timestamp};
    if (s.find(v) != s.end()) return false;
    if (q.size() == memoryLimit) forwardPacket();
    q.push(v);
    s.insert(v);
    mp[destination].push_back(timestamp);
    return true;
  }
  
  vector<int> forwardPacket() {
    if (q.empty()) return {};
    vector<int> v = q.front(); q.pop();
    s.erase(v);
    mp[v[1]].pop_front();
    return v;
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