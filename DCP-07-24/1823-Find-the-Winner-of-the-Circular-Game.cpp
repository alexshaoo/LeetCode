class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1) return 1;
        return (k-1 + findTheWinner(n-1, k)) % n + 1;
    }
};