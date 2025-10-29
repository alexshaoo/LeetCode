class Solution {
public:
  int smallestNumber(int n) {
    vector<int> v;
    for (int i = 2; ; i *= 2) {
      v.push_back(i-1);
      if (i-2 > 1000) break;
    }
    return *lower_bound(v.begin(), v.end(), n);
  }
};