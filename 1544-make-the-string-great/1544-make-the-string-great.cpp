class Solution {
public:
  string makeGood(string s) {
    string ans;
    for (int i = 0 ; i < s.size() ; i++) {
      char curr = s[i];
      ans.push_back(curr);
      while (ans.size() && (ans.back()==s[i+1]+32 || ans.back()==s[i+1]-32)) {
        ans.pop_back();
        i++;
      }
    }
    return ans;
  }
};