class Solution {
public:
  int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    int ans = 0;
    const int n = img1.size();
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        pair coord = make_pair(i, j);
        if (img1[i][j] == 1) a.push_back(coord);
        if (img2[i][j] == 1) b.push_back(coord);
      }
    }
    map<pair<int, int>, int> mp;
    for (const auto& aa : a) {
      for (const auto& bb : b) {
        mp[{aa.first-bb.first,aa.second-bb.second}] += 1;
        ans = max(ans, mp[{aa.first-bb.first,aa.second-bb.second}]);
      }
    }
    return ans;
  }
};