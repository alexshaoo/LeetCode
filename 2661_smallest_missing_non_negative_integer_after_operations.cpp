class Solution {
public:
  int findSmallestInteger(vector<int>& nums, int value) {
    vector<int> mods(value, 0);
    for (int num : nums) {
      mods[((num%value)+value)%value]++;
    }
    int idx = 0, mn = INT_MAX;
    for (int i = 0; i < value; ++i) {
      if (mods[i] < mn) {
        idx = i;
        mn = mods[i];
      }
    }
    return mn*value+idx;
  }
};