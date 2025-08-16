class Solution {
public:
    int maximum69Number(int num) {
        int p = -1, di = -1;
        int n = num;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            ++di;
            if (digit == 6) p = di;
        }
        if (p == -1) return num;
        return num + 3 * pow(10, p);
    }
};