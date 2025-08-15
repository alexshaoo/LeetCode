class Solution {
public:
    bool isPowerOfFour(int n) {
        long long curPow = 1;
        while (curPow < n) curPow *= 4;
        return curPow == n;
    }
};