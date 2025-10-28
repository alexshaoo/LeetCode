class Solution {
public:
  int countValidSelections(vector<int>& nums) {
    int cnt = 0;
    int sm = accumulate(nums.begin(), nums.end(), 0);
    int lsm = 0;
    int idx = 0;
    auto f = [&](int inc) {
      while (idx < nums.size() && nums[idx] == 0) {
        cnt += inc;
        ++idx;
      }
    };
    while (idx < nums.size()) {
      if (nums[idx] != 0) {
        lsm += nums[idx];
        ++idx;
      } else {
        if (sm % 2 == 0) {
          if (lsm == sm/2) {
            f(2);
            break;
          } else f(0);
        } else {
          if (lsm == sm/2) {
            f(1);
          } else if (lsm == sm/2+1) {
            f(1);
            break;
          } else f(0);
        }
      }
    }
    return cnt;
  }
};