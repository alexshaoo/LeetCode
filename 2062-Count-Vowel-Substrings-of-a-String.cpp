class Solution {
public:
    int countVowelSubstrings(string word) {
        auto v = [](char c) -> bool {
            return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        };
        int n = word.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<char> s;
            for (int j = i; j < n; ++j) {
                if (!v(word[j])) break;
                s.insert(word[j]);
                if (s.size() == 5) ++ans;
            }
        }
        return ans;
    }
};