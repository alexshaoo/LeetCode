class Solution {
public:
  int numberOfBeams(vector<string>& bank) {
    vector<int> layers;
    for (string row : bank) {
      int cnt = 0;
      for (char c : row) if (c == '1') ++cnt;
      if (cnt > 0) layers.push_back(cnt);
    }
    if (layers.size() < 2) return 0;
    int ans = 0;
    for (int i = 0; i < layers.size()-1; ++i) ans += layers[i] * layers[i+1];
    return ans;
  }
};