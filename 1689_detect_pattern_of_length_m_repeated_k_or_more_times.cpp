class Solution {
public:
  bool containsPattern(vector<int>& arr, int m, int k) {
    int n = arr.size();
    for (int i = 0; i <= n-m*k; ++i) {
      bool matches = true;
      for (int j = 0; j < m; ++j) {
        int val = arr[i+j];
        int idx = j;
        while (idx < m*k) {
          if (arr[i+idx] != val) matches = false;
          idx += m;
        }
      }
      if (matches) return true;
    }
    return false;
  }
};