class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double, int, int>> pq;
        auto gain = [&](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass/total;
        };
        double tot = 0;
        for (vector<int> c : classes) {
            int pass = c[0];
            int total = c[1];
            tot += (double)pass/total;
            pq.push(make_tuple(gain(pass, total), pass, total));
        }
        while (extraStudents--) {
            auto t = pq.top();
            pq.pop();
            tot += get<0>(t);
            int pass = get<1>(t)+1;
            int total = get<2>(t)+1;
            pq.push(make_tuple(gain(pass, total), pass, total));
        }
        return tot / classes.size();
    }
};