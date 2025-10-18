class Solution {
public:
  int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int distinct = 0;
    int prev = INT_MIN;
    for (int num : nums) {
      if (prev < num+k) {
        ++distinct;
        prev = max(prev+1, num-k);
      }
    }
    return distinct;
  }
};