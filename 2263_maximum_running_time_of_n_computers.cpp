class Solution {
public:
  long long maxRunTime(int n, vector<int>& batteries) {
    sort(batteries.begin(), batteries.end(), greater<int>());
    long long sm = accumulate(batteries.begin(), batteries.end(), 0LL);
    long long mx = sm / n;
    int dedicated = 0;
    while (batteries[dedicated] > sm / (n-dedicated)) {
      sm -= batteries[dedicated];
      ++dedicated;
    }
    return sm / (n-dedicated);
  }
};