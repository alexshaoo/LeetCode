class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size(), t = 0;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += customers[i][1] + max(0, t - customers[i][0]);
            t = customers[i][1] + max(customers[i][0], t);
        }
        return (double)ans/n;
    }
};