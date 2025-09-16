class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    vector<int> ans;
    for (int num : nums) {
      while (true) {
        int g = (ans.empty() ? 1 : gcd(num, ans.back()));
        if (g <= 1) break;
        num *= ans.back() / g;
        ans.pop_back();
      }
      ans.push_back(num);
    }
    return ans;
  }
};