class Solution {
struct Pass {
    double num;
    double denom;
    bool operator<(const Pass& other) const {
        double inc = (num+1)/(denom+1) - num/denom;
        double otherInc = (other.num+1)/(other.denom+1) - other.num/other.denom;
        return inc < otherInc;
    }
};

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Pass> pq;
        for (auto c : classes) {
            int pass = c[0], total = c[1];
            pq.push(Pass(pass, total));
        }
        while (extraStudents--) {
            auto c = pq.top();
            pq.pop();
            c.num++;
            c.denom++;
            pq.push(c);
        }
        double ans = 0;
        while (!pq.empty()) {
            auto c = pq.top();
            pq.pop();
            ans += (double)c.num / c.denom;
        }
        return ans / classes.size();
    }
};