class Solution {
public:
  int mergeStones(vector<int>& stones, int k) {

    const int INF = 0x3f3f3f3f;
    const int s = stones.size();

    // conditional check for when it's impossible
    if ((s-1) % (k-1) != 0) return -1;

    // dp on start to end
    int ps[s+1];
    int dp[s+1][s+1];
    
    memset(ps, 0, sizeof(ps));
    memset(dp, 0, sizeof(dp));

    // generate prefix sum arr
    for (int i = 0; i < s; ++i) ps[i+1] = ps[i] + stones[i]; 

    // dp
    for (int size = k; size <= s; ++size) {
      for (int l = 0; l <= s-size; ++l) {
        int r = l + size - 1;

        // find minimal cost for l to r
        dp[l][r] = INF;

        // piles of K-1
        for (int p = l; p < r; p += (k-1)) dp[l][r] = min(dp[l][r], dp[l][p] + dp[p+1][r]);
        
        cout << "l: " << l << ", r: " << r << "\n";
        
        // if grouping, add cost as well
        if ((r-l) % (k-1) == 0) dp[l][r] += (ps[r+1] - ps[l]);
      }
    }

    return dp[0][s-1];
  }
};