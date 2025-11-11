class Solution {
public:
  string removeDuplicates(string s) {
    int n = s.length();
    stack<char> st;
    string ans = "";
    for (char c : s) {
      if (!st.empty() && c == st.top()) {
        st.pop();
      } else {
        st.push(c);
      }
    }
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};