class Solution {
public:
  int maximumEnergy(vector<int>& energy, int k) {
    int n = energy.size();
    int mx = -1005;
    for (int i = n-k; i < n; ++i) {
      int sm = 0;
      for (int j = 0; i-j >= 0; j += k) {
        sm += energy[i-j];
        mx = max(mx, sm);
      }
    }
    return mx;
  }
};