using ll = long long;
class Solution {
public:
  vector<long long> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<ll> ans(n-k+1);
    unordered_map<int, int> freq;
    set<pair<int, int>, greater<pair<int, int>>> top; // freq, num
    set<pair<int, int>, greater<pair<int, int>>> bot; // freq, num
    ll sm = 0;
    for (int i = 0; i < k; ++i) freq[nums[i]]++;
    for (const auto& [k, v] : freq) bot.insert({v, k});
    for (int i = 0; !bot.empty() && i < x; ++i) {
      auto it = bot.begin();
      sm += 1LL * it->first * it->second;
      top.insert(*it);
      bot.erase(it);
    }
    ans[0] = sm;
    auto remove = [&](int idx) {
      int num = nums[idx];
      int f = freq[num];
      pair<int, int> p = {f, num};
      if (top.contains(p)) {
        sm -= 1LL * num * f;
        top.erase(p);
      } else {
        bot.erase(p);
      }
      if (f > 1) {
        bot.insert({f-1, num});
      }
      if (top.size() < x && !bot.empty()) {
        auto it = bot.begin();
        sm += 1LL * it->first * it->second;
        top.insert(*it);
        bot.erase(it);
      }
      freq[num]--;
    };
    auto add = [&](int idx) {
      int num = nums[idx];
      int f = freq[num];
      pair<int, int> p = {f, num};
      if (top.contains(p)) {
        sm -= 1LL * num * f;
        top.erase(p);
      } else if (bot.contains(p)) {
        bot.erase(p);
      }
      sm += 1LL * num * (f+1);
      top.insert({f+1, num});
      if (top.size() > x) {
        auto it = prev(top.end());
        sm -= 1LL * it->first * it->second;
        bot.insert(*it);
        top.erase(it);
      }
      freq[num]++;
    };
    for (int i = 0; i < n-k; ++i) {
      remove(i);
      add(i+k);
      ans[i+1] = sm;
    }
    return ans;
  }
};