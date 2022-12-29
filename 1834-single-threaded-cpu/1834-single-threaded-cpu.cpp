class Solution {
public:
    using ll = long long;
    vector<int> getOrder(vector<vector<int>>& T) {
        for(int i = 0; i < T.size(); i++) T[i].push_back(i);
        sort(begin(T), end(T));
        auto cmp = [](vector<int>& a, vector<int>& b){return a[1] == b[1] ? a[2] > b[2] : a[1] > b[1];};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        ll cur = 0, idx = 0;
        vector<int> res;
        while(!pq.empty() || idx < T.size()) {
            if(pq.empty() && T[idx][0] > cur) cur = T[idx][0];
            while(idx < T.size() && T[idx][0] <= cur) pq.push(T[idx++]);
            auto p = pq.top(); pq.pop();
            res.push_back(p[2]);
            cur += p[1];
        }
        return res;
    }
};