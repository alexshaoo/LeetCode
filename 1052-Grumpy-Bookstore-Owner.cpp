class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sm = 0;
        for (int i = 0; i < n; ++i) {
            if (i < minutes) sm += customers[i];
            else sm += (!grumpy[i] * customers[i]);
        }
        int ans = sm;
        for (int i = 0; i < n - minutes; ++i) {
            if (grumpy[i + minutes]) sm += customers[i + minutes];
            if (grumpy[i]) sm -= customers[i];
            ans = max(ans, sm);
        }
        return ans;
    }
};