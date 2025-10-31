class Solution {
public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int n = tops.size();
    vector<int> freq(7, 0);
    int cand = -1;
    for (int i = 0; i < n; ++i) {
      freq[tops[i]]++;
      freq[bottoms[i]]++;
      if (freq[tops[i]] >= n) {
        cand = tops[i];
        break;
      }
      if (freq[bottoms[i]] >= n) {
        cand = bottoms[i];
        break;
      }
    }
    if (cand == -1) return -1;
    int mt = 0, mb = 0;
    for (int i = 0; i < n; ++i) {
      if (tops[i] != cand && bottoms[i] != cand) return -1;
      if (tops[i] != cand) ++mt;
      if (bottoms[i] != cand) ++mb;
    }
    return min(mt, mb);
  }
};