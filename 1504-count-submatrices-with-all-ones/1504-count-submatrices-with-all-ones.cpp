class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> heights(m, 0), cnt(m, 0);
        int ans = 0;
        for (int r = 0; r < n; ++r) {
            stack<int> st;
            for (int c = 0; c < m; ++c) {
                heights[c] = (mat[r][c] == 0 ? 0 : heights[c] + 1);
                while (st.size() > 0 && heights[st.top()] >= heights[c]) st.pop();
                if (st.size() == 0) {
                    cnt[c] = heights[c] * (c+1);
                } else {
                    cnt[c] = heights[c] * (c-st.top()) + cnt[st.top()];
                }
                ans += cnt[c];
                st.push(c);
            }
        }
        return ans;
    }
};