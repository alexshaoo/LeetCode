class Solution {
public:
    bool check(int target, int num) {
        if (num == target) return true;
        if (target < 0 || num < target) return false;
        return check(target-num%10, num/10) || check(target-num%100, num/100) || check(target-num%1000, num/1000);
    }
    int punishmentNumber(int n) {
        int c = 0;
        check(36, 36*36);
        for (int i = 1; i <= n; ++i) {
            if (check(i, i*i)) {
                c += i*i;
            }
        }
        return c;
    }
};