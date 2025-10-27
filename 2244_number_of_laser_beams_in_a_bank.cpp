class Solution {
public:
  int numberOfBeams(vector<string>& bank) {
    int ans = 0;
    int prev = 0;
    for (const string& row : bank) {
      int cnt = count(row.begin(), row.end(), '1');
      if (cnt > 0) {
        ans += cnt * prev;
        prev = cnt;
      }
    }
    return ans;
  }
};