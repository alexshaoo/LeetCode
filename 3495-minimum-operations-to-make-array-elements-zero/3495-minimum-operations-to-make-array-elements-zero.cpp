class Solution {
public:
    // number of operations needed for [1, num]
    long long f(int num) {
        long long res = 0, p = 4, val = 1, factor = 1;
        while (4*val <= num) {
            res += (p-val) * factor;
            ++factor;
            p *= 4;
            val *= 4;
        }
        res += (num-val+1)*factor;
        return res;
        
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto q : queries) {
            long long cnt = f(q[1]) - f(q[0]-1);
            ans += (cnt + 1) / 2;
        }
        return ans;
    }
};