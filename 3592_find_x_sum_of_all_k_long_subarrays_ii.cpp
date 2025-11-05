using ll = long long;
class Solution {
public:
  vector<long long> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    unordered_map<int, int> freq;
    for (int i = 0; i < k; ++i) freq[nums[i]]++;
    set<pair<int, int>, greater<pair<int, int>>> top, bot; // freq, num
    ll sm = 0;
    for (const auto& [k, v] : freq) bot.insert({v, k});
    for (int i = 0; !bot.empty() && i < x; ++i) {
      auto it = bot.begin();
      sm += 1LL * it->first * it->second;
      top.insert(*it);
      bot.erase(it);
    }
    vector<ll> ans(n-k+1);
    ans[0] = sm;
    auto rm = [&](int num, int f) {
      pair<int, int> p = {f, num};
      if (top.contains(p)) {
        sm -= 1LL * num * f;
        top.erase(p);
      } else {
        bot.erase(p);
      }
    };
    auto remove = [&](int num, int f) {
      rm(num, f);
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
    auto add = [&](int num, int f) {
      rm(num, f);
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
      remove(nums[i], freq[nums[i]]);
      add(nums[i+k], freq[nums[i+k]]);
      ans[i+1] = sm;
    }
    return ans;
  }
};