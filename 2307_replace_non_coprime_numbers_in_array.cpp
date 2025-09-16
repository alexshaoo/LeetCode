class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    list<int> ans(nums.begin(), nums.end());
    for (auto it = ans.begin(); it != ans.end(); ++it) {
      if (it != ans.begin()) {
        int l = *prev(it);
        int r = *it;
        int g = gcd(l, r);
        if (g > 1) {
          ans.erase(prev(it));
          *it = (long long)l*r / g;
          --it;
        }
      }
    }
    return vector<int>(ans.begin(), ans.end());
  }
};