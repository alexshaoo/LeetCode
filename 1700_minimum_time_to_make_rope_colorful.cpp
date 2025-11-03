class Solution {
public:
  int minCost(string colors, vector<int>& neededTime) {
    int n = colors.length();
    int idx = 0;
    int time = 0;
    while (idx < n-1) {
      if (colors[idx] == colors[idx+1]) {
        if (neededTime[idx] > neededTime[idx+1]) swap(neededTime[idx], neededTime[idx+1]);
        time += neededTime[idx];
      }
      ++idx;
    }
    return time;
  }
};