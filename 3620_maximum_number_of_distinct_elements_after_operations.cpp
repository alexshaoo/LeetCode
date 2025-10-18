class Solution {
public:
  int maxDistinctElements(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int distinct = 1;
    long long transformed = nums[0]-k;
    for (int i = 1; i < n; ++i) {
      long long l = nums[i]-k, r = nums[i]+k;
      if (transformed+1 < l) {
        ++distinct;
        transformed = l;
      } else if (transformed+1 >= l && transformed+1 <= r) {
        ++distinct;
        transformed++;
      }
    }
    return distinct;
  }
};