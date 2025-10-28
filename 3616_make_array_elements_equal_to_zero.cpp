class Solution {
public:
  bool sim(vector<int> nums, int pos, bool left) {
    while (pos >= 0 && pos < nums.size()) {
      if (nums[pos] != 0) { 
        nums[pos]--;
        left = !left;
      }
      pos += (left ? -1 : 1);
    }
    for (int num : nums) if (num != 0) return false;
    return true;
  }
  int countValidSelections(vector<int>& nums) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) continue;
      cnt += sim(nums, i, true) + sim(nums, i, false);
    }
    return cnt;
  }
};