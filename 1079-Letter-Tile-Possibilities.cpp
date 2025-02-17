class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        unordered_set<string> s;
        do {
            for (int i = 1; i <= n; ++i) s.insert(tiles.substr(0, i));
        } while (next_permutation(tiles.begin(), tiles.end()));
        return s.size();
    }
};