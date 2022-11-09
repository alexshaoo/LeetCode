class StockSpanner {
public:
  stack<pair<int, int>> s;
  int next(int price) {
    int n = 1;
    while (!s.empty() && s.top().first <= price) {
      n += s.top().second;
      s.pop();
    }
    s.push({price, n});
    return n;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */