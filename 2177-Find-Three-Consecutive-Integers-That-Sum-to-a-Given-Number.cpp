class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        return num % 3 == 0 ? ([](long long n) { vector<long long> res(3); iota(res.begin(), res.end(), n); return res; })(num / 3 - 1) : vector<long long>{};
    }
};