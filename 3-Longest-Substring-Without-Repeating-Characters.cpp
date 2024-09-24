class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        int l = 0, r = 0;
        unordered_set<char> st;
        while (r < n) {
            while (st.contains(s[r])) {
                st.erase(s[l++]);
            }
            st.insert(s[r++]);
            ans = max(ans, r-l);
        }
        return ans;
    }
};