class Solution {
public:
  vector<int> getSneakyNumbers(vector<int>& nums) {
    int n = nums.size()-2;
    int nx = 0, sx = 0;
    for (int num : nums) nx ^= num;
    for (int i = 1; i < n; ++i) sx ^= i;
    int abx = nx ^ sx;
    int d = abx & (-abx);
    int w = 0, wo = 0;
    for (int num : nums) {
      if (num & d) w ^= num;
      else wo ^= num;
    }
    for (int i = 1; i < n; ++i) {
      if (i & d) w ^= i;
      else wo ^= i;
    }
    return {w, wo};
  }
};