class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for (char c : s) {
            if (ans >= 0) {
                if (c == ' ') ans *= -1;
                else ++ans;
            } else {
                if (c != ' ') ans = 1;
            }
        }
        return abs(ans);
    }
};