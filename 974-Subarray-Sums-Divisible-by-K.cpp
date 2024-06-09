class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> mp;
        mp[0] = 1;
        int s = 0;
        for (const auto& num : nums) {
            s = (s + num % k + k) % k;
            ans += mp[s]++;
        }
        return ans;        
    }
};