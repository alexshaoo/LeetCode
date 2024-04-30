class Solution {
public:
  long long wonderfulSubstrings(string word) {
    int bitmask = 0;
    unordered_map<int, int> pb;
    pb[0] = 1;
    long long ans = 0;
    for (const auto& ch : word) {
      bitmask ^= (1 << (ch - 'a'));
      // all even
      ans += pb[bitmask];
      // one odd
      for (int i = 0; i < 10; ++i) {
        ans += pb[bitmask ^ 1 << i];
      }
      ++pb[bitmask];
    }
    return ans;
  }
};