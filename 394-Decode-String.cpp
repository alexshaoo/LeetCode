class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<pair<int, string>> st;
        string ans = \\;
        int i = 0;
        while (i < n) {
            // number
            if (s[i] >= '0' && s[i] <= '9') {
                int num = (s[i]-'0');
                ++i;
                while (s[i] >= '0' && s[i] <= '9') {
                    num = 10*num+(s[i++]-'0');
                }
                st.push({num, \\});
                // open bracket, don't care
            } else if (s[i] >= 'a' && s[i] <= 'z') { // string
                if (st.size() == 0) {
                    ans += s[i];
                } else {
                    st.top().second += s[i];
                }
            } else if (s[i] == ']') { // close bracket
                string curr = \\;
                auto [num, tmp] = st.top();
                st.pop();
                while (num--) {
                    curr += tmp;
                }
                if (st.size() == 0) {
                    ans += curr;
                } else {
                    st.top().second += curr;
                }
            }
            ++i;
        }
        return ans;
    }
};