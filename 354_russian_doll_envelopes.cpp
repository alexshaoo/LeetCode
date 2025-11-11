class Solution {
public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n = envelopes.size();
    if (n == 0) return 0;
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
      if (a[0] == b[0]) return a[1] > b[1];
      return a[0] < b[0];
    });
    vector<int> tails;
    for (const auto& e : envelopes) {
      auto it = lower_bound(tails.begin(), tails.end(), e[1]);
      if (it == tails.end()) tails.push_back(e[1]);
      else *it = e[1];
    }
    return tails.size();
  }
};