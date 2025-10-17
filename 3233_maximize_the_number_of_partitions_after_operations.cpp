class Solution {
  unordered_map<long long, int> mp;
public:
  int f(string& s, int k, long long idx, long long curSet, bool change) {
    if (idx == s.length()) return 0;
    long long key = (idx << 27) | (curSet << 1) | change;
    if (mp.count(key)) return mp[key];
    int ans = 0;
    int ch = s[idx]-'a';
    long long updatedSet = curSet | (1 << ch);
    // don't change
    if (__builtin_popcount(updatedSet) > k) {
      ans = max(ans, 1 + f(s, k, idx+1, 1 << ch, change));
    } else {
      ans = max(ans, f(s, k, idx+1, updatedSet, change));
    }
    // change
    if (change) {
      for (int nc = 0; nc < 26; ++nc) {
        if (nc == ch) continue;
        long long changedSet = curSet | (1 << nc);
        if (__builtin_popcount(changedSet) > k) {
          ans = max(ans, 1 + f(s, k, idx+1, 1 << nc, false));
        } else {
          ans = max(ans, f(s, k, idx+1, changedSet, false));
        }
      }
    }
    mp[key] = ans;
    return ans;
  }
  int maxPartitionsAfterOperations(string s, int k) {
    return 1 + f(s, k, 0LL, 0LL, true);
  }
};