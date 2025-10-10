class Solution {
public:
  int maximumEnergy(vector<int>& energy, int k) {
    int n = energy.size();
    int mx = -1005;
    vector<int> ps(n+k);
    for (int i = 0; i < n; ++i) {
      ps[i+k] = ps[i] + energy[i];
    }
    for (int i = n; i < n+k; ++i) {
      int j = i%k;
      while (j < n) {
        mx = max(mx, ps[i]-ps[j]);
        j += k;
      }
    }
    return mx;
  }
};