class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int ans = 0;
    heights.push_back(0);
    vector<int> ind;

    for (int i = 0; i < heights.size(); ++i) {
      while (ind.size() > 0 && heights[i] < heights[ind.back()]) {
        int h = heights[ind.back()];
        ind.pop_back();

        int j = 0;
        if (ind.size() > 0)
          j = ind.back();
        else
          j = -1;

        ans = max(ans, h * (i - j - 1));
      }

      ind.push_back(i);
    }

    return ans;
  }
};