class Solution {
public:
  string removeDuplicates(string s) {
    string st;
    for (const auto& ch : s) {
      if (st.back() == ch) {
        st.pop_back();
      } else {
        st += ch;
      }
    }
    return st;
  }
};