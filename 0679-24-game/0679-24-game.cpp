class Solution {
public:
    double calc(int op, double a, double b) {
        if (op == 0) return a+b;
        if (op == 1) return a-b;
        if (op == 2) return a*b;
        return b > 0 ? a/b : 0;
    }
    bool judgePoint24(vector<int>& cards) {
        return helper({cards.begin(), cards.end()}, 4);
    }
    bool helper(vector<double> cards, int n) {
        if (n == 1) return abs(cards[0] - 24.0) < 1e-10;
        sort(cards.begin(), cards.end());
        do {
            double a = cards[n-2], b = cards[n-1];
            // cout << a << ' ' << b << '\n';
            vector<double> v(cards.begin(), cards.end()-1);
            for (int op = 0; op < 4; ++op) {
                v.back() = calc(op, a, b);
                if (helper(v, n-1)) return true;
            }
        } while(next_permutation(cards.begin(), cards.end()));
        return false;
    }
};