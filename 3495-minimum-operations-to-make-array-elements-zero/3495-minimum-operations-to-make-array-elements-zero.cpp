class Solution {
public:
    long long f(long long num) {
        long long d = 0;
        while (num > 0) {
            ++d;
            num /= 4;
        }
        return d;
    }
    long long minOperations(vector<vector<int>>& queries) {
        vector<long long> p;
        for (long long i = 1; i <= 4*1e9+5; i *= 4) p.push_back(i);
        long long sm = 0;
        for (auto q : queries) {
            long long l = q[0], r = q[1];
            if (r-l == 1) {
                sm += f(r);
            } else {
                long long lp = 0, rp = 0;
                while (p[lp+1] <= l) ++lp;
                while (p[rp+1] <= r) ++rp;
                long long c = 0;
                for (long long i = lp; i <= rp; ++i) {
                    c += (p[i+1]-p[i])*(i+1);
                }
                // trim off left and right
                c -= (l-p[lp])*(lp+1);
                c -= (p[rp+1]-r-1)*(rp+1);
                sm += (c+1)/2;
            }
        }
        return sm;
    }
};