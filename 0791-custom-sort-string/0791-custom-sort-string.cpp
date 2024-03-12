class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, pair<int, bool>> c;
        for (auto ch : s) {
            if (c.find(ch) != c.end()) c[ch].first++;
            else c[ch].first = 1;
        }
        string ans = "";
        for (auto ch : order) {
            if (c.find(ch) != c.end()) {
                for (int i = 0 ; i < c[ch].first; ++i) ans += ch;
                c[ch].second = true;
            }
        }
        for (auto ch : s) {
            if (!c[ch].second) {
                ans += ch;
            }
        }
        return ans;
    }
};