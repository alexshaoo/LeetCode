class Solution {
    public:
        string minRemoveToMakeValid(string s) {
        int o = 0, c = count(s.begin(), s.end(), ')');
        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' && c != 0) {
                ans += s[i];
                --c;
                ++o;
            } else if (s[i] == ')' && o != 0) {
                ans += s[i];
                --o;
            } else if (s[i] == ')') {
                --c;
            } else if (s[i] != ')' && s[i] != '(') {
                ans += s[i];
            }
        }
        return ans;        
    }
};