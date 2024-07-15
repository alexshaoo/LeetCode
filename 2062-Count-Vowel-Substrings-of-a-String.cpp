class Solution {
public:
    int f(string& word, int k) {
        auto v = [](char c) -> bool {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int n = word.length();
        int ans = 0;
        unordered_map<char, int> mp;
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (!v(word[j])) {
                i = j + 1;
                mp.clear();
                continue;
            }
            mp[word[j]]++;
            while (mp.size() > k) {
                mp[word[i]]--;
                if (mp[word[i]] == 0) mp.erase(word[i]);
                ++i;
            }
            ans += j-i+1;
        }
        return ans;
    }
    int countVowelSubstrings(string word) {
        return f(word, 5) - f(word, 4);
    }
};