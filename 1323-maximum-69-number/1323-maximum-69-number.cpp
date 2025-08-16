class Solution {
public:
    int maximum69Number(int num) {
        // string ans = string(num);
        // for (char& digit : ans) {
        //     if (digit == '6') {
        //         digit = '9';
        //         return stoi(ans);
        //     }
        // }
        // return num-3;
        int ans = num;
        int pow = 1, highestPow = 0;
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            if (digit == 6) {
                highestPow = pow;
            }
            pow *= 10;
        }
        return ans + (3 * highestPow);
    }
};