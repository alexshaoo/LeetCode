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

  int maximalRectangle(vector<vector<char>>& matrix) {
    // usin code from q84
    int sum = 0;
    vector<int> heights(matrix[0].size(), 0);

    int ans = 0;

    for (int i = 0; i < matrix.size(); ++i) {
      sum = 0;

      for (int j = 0; j < matrix[i].size(); ++j) {
        if (matrix[i][j] == '1')
          ++heights[j];
        else
          heights[j] = 0;
      }

      ans = max(ans, largestRectangleArea(heights));
    }

    return ans;
  }
};