class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        int totalClose = count(s.begin(), s.end(), ')');

        string ans = "";
        for (char ch : s) {
            if (ch == '(') {
                if (totalClose > 0) {
                    ans += ch;
                    open++;
                    totalClose--;
                }
            } else if (ch == ')') {
                if (open > 0) {
                    ans += ch;
                    open--;
                } else {
                    totalClose--;
                }
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};