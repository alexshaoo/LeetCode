class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> fib = {1, 2};
        
        for (int i = 2; i < n; ++i) {
            fib.push_back(fib[i-1] + fib[i-2]);
        }
        
        return fib[n-1];
        
    }
};