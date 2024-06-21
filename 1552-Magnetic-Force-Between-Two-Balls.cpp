class Solution {
public:
    int valid(vector<int>& position, int dist, int balls) {
        int n = position.size();
        int c = 1;
        int last = position[0];
        for (int i = 1; i < n; ++i) {
            if (position[i] - last >= dist) {
                ++c;
                last = position[i];
            }
            if (c >= balls) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int mx = *max_element(position.begin(), position.end());
        long long l = 1, r = 1e9, ans = 1;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (valid(position, mid, m))  {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};