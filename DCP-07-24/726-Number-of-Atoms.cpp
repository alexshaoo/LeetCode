class Solution {
public:
    pair<int, int> get(string s, int i) {
        int j = i, n = s.length();
        while (i < n && isdigit(s.at(i))) --i;
        return {stoi(s.substr(++i, j-i+1)), j-i+1};
    }
    string countOfAtoms(string formula) {
        int n = formula.length();
        map<string, int> mp;
        stack<int> s;
        s.push(1);
        int f = 1;
        for (int i = n - 1; i >= 0; --i) {
            const auto c = formula.at(i);
            if (c == '(') s.pop();
            else if (c == ')') s.push(f * s.top());
            else if (isdigit(c)) {
                auto [n, l] = get(formula, i);
                f = n;
                i -= --l;
                continue;
            } else if (islower(c)) mp[formula.substr(--i, 2)] += f * s.top();
            else mp[formula.substr(i, 1)] += f * s.top();
            f = 1;
        }
        string ans;
        for (const auto& [k, v] : mp) {
            ans += k;
            if (v > 1) ans += to_string(v);
        }
        return ans;
    }
};
