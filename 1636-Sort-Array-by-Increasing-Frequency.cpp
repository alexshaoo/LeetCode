class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) mp[num]++;
        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            return a.second == b.second ? a.first > b.first : a.second < b.second;
        });
        vector<int> ans;
        for (auto& [a, b] : v) {
            while (b--) ans.push_back(a);
        }
        return ans;
    }
};