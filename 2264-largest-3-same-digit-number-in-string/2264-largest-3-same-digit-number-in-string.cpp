class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.length();
        for (int i = 0; i <= n-3; ++i) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                if (ans == "" || num[i] > ans[0]) ans = string(3, num[i]);
            }
        }
        return ans;
    }
};