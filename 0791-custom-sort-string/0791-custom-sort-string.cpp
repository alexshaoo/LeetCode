class Solution {
public:
    string customSortString(string order, string s) {
        int fre[26] = {0};
        bitset<26> ord;
        for (auto c : order) {
            ord[c - 'a'] = 1;
        }
        string ans;
        for (auto c : s) {
            if (ord[c - 'a'] == 0) {
                ans += c;
            } else {
                ++fre[c - 'a'];
            }
        }
        for (auto c : order) {
            ans += string(fre[c - 'a'], c);
        }
        return ans;
    }
};