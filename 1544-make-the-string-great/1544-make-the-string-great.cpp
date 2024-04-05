class Solution {
public:
    string makeGood(string s) {
        s += '@';
        while (1) {
            int n = s.length();
            string ans = "";
            for (int i = 0; i < n - 1; ++i) {
                if (s[i] - 'a' == s[i + 1] - 'A' || s[i] - 'A' == s[i + 1] - 'a') {
                    ++i;
                } else {
                    ans += s[i];
                }
            }
            ans += s[n - 1];
            if (ans == s) {
                return ans.substr(0, n-1);
            }
            s = ans;
        }
    }
};