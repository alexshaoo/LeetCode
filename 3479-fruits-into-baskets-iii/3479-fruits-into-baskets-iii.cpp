class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<pair<int, int>> sortedBasketsToIndex(n);
        for (int i = 0; i < n; ++i) {
            sortedBasketsToIndex[i] = {baskets[i], i};
        }
        sort(sortedBasketsToIndex.begin(), sortedBasketsToIndex.end());
        vector<int> unsortedIndexToSortedIndex(n);
        for (int i = 0; i < n; ++i) {
            unsortedIndexToSortedIndex[sortedBasketsToIndex[i].second] = i;
        }
        // segtree for the smallest index i in the unsorted baskets list, such that, when sorted, the basket is in a given range [l, r]
        vector<int> segtree(4*n, INT_MAX);
        function<void(int, int, int)> build = [&](int v, int tl, int tr) {
            if (tl == tr) segtree[v] = sortedBasketsToIndex[tl].second;
            else {
                int tm = (tl + tr) / 2;
                build(2*v+1, tl, tm);
                build(2*v+2, tm+1, tr);
                segtree[v] = min(segtree[2*v+1], segtree[2*v+2]);
            }
        };
        function<int(int, int, int, int, int)> query = [&](int v, int tl, int tr, int l, int r) -> int {
            if (l > r) return INT_MAX;
            if (l == tl && r == tr) return segtree[v];
            int tm = (tl + tr) / 2;
            return min(query(2*v+1, tl, tm, l, min(r, tm)), query(2*v+2, tm+1, tr, max(l, tm+1), r));
        };
        function<void(int, int, int, int, int)> update = [&](int v, int tl, int tr, int pos, int new_val) {
            if (tl == tr) segtree[v] = new_val;
            else {
                int tm = (tl + tr) / 2;
                if (pos <= tm) update(2*v+1, tl, tm, pos, new_val);
                else update(2*v+2, tm+1, tr, pos, new_val);
                segtree[v] = min(segtree[2*v+1], segtree[2*v+2]);
            }
        };
        build(0, 0, n-1);
        sort(baskets.begin(), baskets.end());
        int ans = n;
        for (int fq : fruits) {
            auto it = lower_bound(baskets.begin(), baskets.end(), fq);
            if (it != baskets.end()) {
                int smallest = query(0, 0, n-1, it-baskets.begin(), n-1);
                if (smallest != INT_MAX) {
                    --ans;
                    update(0, 0, n-1, unsortedIndexToSortedIndex[smallest], INT_MAX);
                }
            }
        }
        return ans;
    }
};