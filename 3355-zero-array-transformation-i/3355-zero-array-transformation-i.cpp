class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1);
        for (auto q : queries) {
            diff[q[0]]++;
            diff[q[1]+1]--;
        }
        vector<int> ps(n+2);
        for (int i = 1; i < n+2; ++i) {
            ps[i] = ps[i-1] + diff[i-1];
        }
        for (int i = 0; i < n; ++i) {
            if (ps[i+1] < nums[i]) return false;
        }
        return true;
    }
};