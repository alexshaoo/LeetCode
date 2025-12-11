class Solution {
public:
  int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    int m = buildings.size();
    vector<bool> vc(m, false), hc(m, false);
    unordered_map<int, set<pair<int, int>>> xm, ym; // x -> {y, idx}, y -> {x, idx}
    for (int i = 0; i < m; ++i) {
      auto v = buildings[i];
      xm[v[0]].insert({v[1], i});
      ym[v[1]].insert({v[0], i});
    }
    for (auto& [x, yi] : xm) {
      for (auto [y, i] : yi) vc[i] = true;
      vc[yi.begin()->second] = false;
      vc[prev(yi.end())->second] = false;
    }
    for (auto& [y, xi] : ym) {
      for (auto [x, i] : xi) hc[i] = true;
      hc[xi.begin()->second] = false;
      hc[prev(xi.end())->second] = false;
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      cnt += (vc[i] && hc[i]);
    }
    return cnt;
  }
};