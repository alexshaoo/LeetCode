class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long s = 0;
        for (int i = 0; i < n; ++i) {
            s += chalk[i];
        }
        k %= s;
        for (int i = 0; i < n; ++i) {
            k -= chalk[i];
            if (k < 0) return i;
        }
        return 0;
    }
};