class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.length();
        int i = 0;
        while (i <= n-3) {
            if (ans != "" && num[i] <= ans[0]) {
                ++i;
                continue;
            }
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                if (ans == "" || num[i] > ans[0]) {
                    ans = string(3, num[i]);
                    i += 3;
                    continue;
                }
            }
            ++i;
        }
        return ans;
    }
};