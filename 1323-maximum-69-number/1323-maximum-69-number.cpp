class Solution {
public:
    int maximum69Number(int num) {
        int p = -1, di = 0;
        int n = num;
        for (int n = num; n > 0; ++di, n/= 10) {
            if (n%10 == 6) p = di;
        }
        if (p == -1) return num;
        return num + 3 * pow(10, p);
    }
};

const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
};