class Solution {
public:
    int valid(vector<int>& arr, int m, int k, long long days) {
        vector<bool> b;
        for (const auto& num : arr) {
            b.push_back(num <= days);
        }
        long long streak = 0, num = 0;
        for (const auto& bb : b) {
            streak = bb ? streak + 1 : 0;
            if (streak == k) {
                ++num;
                streak = 0;
            }
        }
        return num >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if (n < (long long)m * k) return -1;
        long long ans = 0;
        long long l = 0, r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l <= r) {
            long long mi = (l + r) / 2;
            if (valid(bloomDay, m, k, mi)) r = mi - 1;
            else l = mi + 1;
        }
        return l;
    }
};