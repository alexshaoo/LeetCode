class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0]) ans.push_back(intervals[i++]);
        while (i < n && intervals[i][0] <= newInterval[1]) newInterval = { min(intervals[i][0], newInterval[0]), max(intervals[i++][1], newInterval[1]) };
        ans.push_back(newInterval);
        while (i < n) ans.push_back(intervals[i++]);
        return ans;
    }
};