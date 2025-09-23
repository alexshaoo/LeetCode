class Solution {
public:
  int compareVersion(string version1, string version2) {
    int sz1 = 0, sz2 = 0;
    int i = 0, j = 0;
    int n = version1.length(), m = version2.length();
    while (i < n || j < m) {
      while (i+sz1 < n && version1[i+sz1] != '.') ++sz1;
      while (j+sz2 < m && version2[j+sz2] != '.') ++sz2;
      int val1 = 0, val2 = 0;
      if (i < n) {
        val1 = stoi(version1.substr(i, sz1));
      }
      if (j < m) {
        val2 = stoi(version2.substr(j, sz2));
      }
      if (val1 < val2) return -1;
      if (val1 > val2) return 1;
      i = (i+sz1+1); sz1 = 0;
      j = (j+sz2+1); sz2 = 0;
    }
    return 0;
  }
};