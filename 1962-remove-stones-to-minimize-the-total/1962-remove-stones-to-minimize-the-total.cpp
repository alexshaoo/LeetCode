class Solution {
public:
  int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> pq;
    for (auto &pile : piles) pq.push(pile);
    while (k--) {
      int p = pq.top();
      pq.pop();
      pq.push(p-p/2);
    }
    int s = 0;
    while (!pq.empty()) {
      s += pq.top();
      pq.pop();
    }
    return s;
  }
};