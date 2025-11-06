class DSU {
public:
    vector<int> p, s;
    int n;
    
    DSU(int c) {
        n = c;
        p.resize(n+1);
        s.resize(n+1, 1);
        for(int i=1; i<=n; i++) p[i] = i;
    }

    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;
        if(s[pu] < s[pv]) swap(pu, pv);
        s[pu] += s[pv];
        p[pv] = pu;
    }

    void ultimate() {
        for(int i=1; i<=n; i++) p[i] = find(p[i]);
    }
};


class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU uf(c);
        for(const auto &i:connections){
            uf.unite(i[0],i[1]);
        }
        uf.ultimate();
        unordered_map<int,set<int>> m;
        for(int i=1;i<=c;i++){
            m[uf.p[i]].insert(i);
        }
        vector<int> ans;
        for(auto const &q:queries){
            int k = uf.p[q[1]];
            if(q[0]==2){
                m[k].erase(q[1]);
            } else {
                if(m[k].find(q[1])!=m[k].end()){
                    ans.push_back(q[1]);
                } else {
                    ans.push_back(m[k].empty()?-1:*m[k].begin());
                }
            }
        }
        return ans;
    }
};