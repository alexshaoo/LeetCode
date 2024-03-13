class Solution {
public:
    int sm(int n) {
        return n * (n + 1) / 2;
    }
    int pivotInteger(int n) {
        int i = 0;
        int t = sm(n);
        while (2*sm(i) < t) {
            ++i;
        }
        if (sm(i) == sm(n) - sm(i-1)) return i;
        return -1;
    }
};