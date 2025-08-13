class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        // 3^k <= 2e31-1 => k <= log_3(2e31-1) => log(2e31-1)/log(3)
        int k = log(pow(2, 31)-1) / log(3);
        return (int)pow(3, k) % n == 0;
    }
};