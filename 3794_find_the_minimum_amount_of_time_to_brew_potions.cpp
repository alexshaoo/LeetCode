class Solution {
public:
  long long minTime(vector<int>& skill, vector<int>& mana) {
    int n = skill.size();
    int m = mana.size();
    vector<long long> arr(n);
    for (int w = 0; w < n; ++w) {
      if (w == 0) arr[w] = mana[0]*skill[w];
      else arr[w] = arr[w-1] + mana[0]*skill[w];
    }
    for (int p = 1; p < m; ++p) {
      long long start = arr[0];
      long long time = 0;
      for (int w = 0; w < n-1; ++w) {
        time += mana[p]*skill[w];
        start += max(0LL, arr[w+1]-(start+time));
      }
      for (int w = 0; w < n; ++w) {
        start += mana[p]*skill[w];
        arr[w] = start;
      }
    }
    return arr[n-1];
  }
};