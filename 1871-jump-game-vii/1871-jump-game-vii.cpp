class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    int l = s.length();
    int c = 0;
    int total[l+1];
	  memset(total, 0, sizeof total);
    
    if (s.back() == '1') {
      return false;
    }
    
    for (int i = 0; i < l; ++i) {
      c += total[i];
      if (i == 0 || (c && s[i] == '0')) {
        ++total[min(i + minJump, l)];
        --total[min(i + maxJump + 1, l)];
      }
    }
    
    return c;
  }
};