class Solution {
public:
    static const int MAX_SZ = 200;
    double dpA[MAX_SZ][MAX_SZ];
    double dpT[MAX_SZ][MAX_SZ];
    double calcA(int n, int m) { // in units (rounded up multiples of 25)
        if (n <= 0 && m <= 0) return 0.0;
        if (n > 0 && m <= 0) return 0.0;
        if (n <= 0 && m > 0) return 1.0;
        double a, b, c, d;
        if (dpA[n][m] != -1) return dpA[n][m];
        double p = 0.25*calcA(n-4, m) + 0.25*calcA(n-3, m-1) + 0.25*calcA(n-2, m-2) + 0.25*calcA(n-1, m-3);
        dpA[n][m] = p;
        return p;
    }
    double calcT(int n, int m) { // in units (rounded up multiples of 25)
        if (n <= 0 && m <= 0) return 1.0;
        if (n > 0 && m <= 0) return 0.0;
        if (n <= 0 && m > 0) return 0.0;
        if (dpT[n][m] != -1) return dpT[n][m];
        double p = 0.25*calcT(n-4, m) + 0.25*calcT(n-3, m-1) + 0.25*calcT(n-2, m-2) + 0.25*calcT(n-1, m-3);
        dpT[n][m] = p;
        return p;
    }
    double soupServings(int n) {
        if (n > 4825) return 1.0;
        int units = ceil(n/25.0);
        fill(&dpA[0][0], &dpA[0][0] + MAX_SZ*MAX_SZ, -1.0);
        fill(&dpT[0][0], &dpT[0][0] + MAX_SZ*MAX_SZ, -1.0);
        return calcA(units, units) + 0.5*calcT(units, units);
    }
};