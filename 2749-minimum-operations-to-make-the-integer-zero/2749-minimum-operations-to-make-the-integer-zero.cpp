class Solution {
public:
    int numOnes(long long num) {
        if (num == 0) return 0;
        return (num&1) ? 1+numOnes(num/2) : numOnes(num/2);
    }
    int makeTheIntegerZero(int num1, int num2) {
        long long n1 = (long long)num1, n2 = (long long)num2;
        // number of bits in binary form of 1e9 - k(-1e9)
        for (long long i = 1; i <= 35; ++i) {
            long long res = n1 - i * num2;
            if (i >= numOnes(res) && i <= res) return i;
        }
        return -1;
    }
};