class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gap;
        gap.push_back(startTime[0]);
        for (int i = 0; i < n-1; ++i) {
            gap.push_back(startTime[i+1] - endTime[i]);
        }
        gap.push_back(eventTime-endTime[n-1]);
        vector<bool> b(n, false);
        int mx = gap[0];
        for (int i = 1; i < n; ++i) {
            if (mx >= endTime[i]-startTime[i]) b[i] = true;
            mx = max(mx, gap[i]);
        }
        mx = gap[n];
        for (int i = n-2; i >= 0; --i) {
            if (mx >= endTime[i]-startTime[i]) b[i] = true;
            mx = max(mx, gap[i+1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int curGap = endTime[i]-startTime[i];
            int lgap = gap[i], rgap = gap[i+1];
            if (b[i]) { // can be moved to other gap
                ans = max(ans, lgap+curGap+rgap);
            } else { // shifted within current gap
                ans = max(ans, lgap+rgap);
            }
        }
        return ans;
    }
};