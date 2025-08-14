class Solution {
public:
    string largestGoodInteger(string num) {
        int ans = -1;
        int i = 0;
        while (i <= num.length()-3) {
            if (ans != -1 && num[i] <= num[ans]) {
                ++i;
                continue;
            }
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                if (ans == -1 || num[i] > num[ans]) {
                    ans = i;
                    i += 3;
                    continue;
                }
            }
            ++i;
        }
        return ans == -1 ? "" : num.substr(ans, 3);
    }
};