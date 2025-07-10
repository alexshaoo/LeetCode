class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> emp;
        emp.push_back(startTime[0]);
        for (int i = 0; i < n-1; ++i) {
            emp.push_back(startTime[i+1] - endTime[i]);
        }
        emp.push_back(eventTime-endTime[n-1]);
        multiset<int, greater<int>> gaps;
        for (int e : emp) gaps.insert(e);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int curGap = endTime[i]-startTime[i];
            int lgap = emp[i], rgap = emp[i+1];
            gaps.erase(gaps.find(lgap));
            gaps.erase(gaps.find(rgap));
            if (*gaps.begin() >= curGap) { // can be moved to other gap
                ans = max(ans, lgap+curGap+rgap);
            } else { // shifted within current gap
                ans = max(ans, lgap+rgap);
            }
            gaps.insert(lgap);
            gaps.insert(rgap);
        }
        return ans;
    }
};