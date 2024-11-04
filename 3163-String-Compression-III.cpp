class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int n = word.size();
        int i = 0;
        while (i < n) {
            int count = 0;
            char ch = word[i];
            while (i < n && count < 9 && word[i] == ch) {
                ++count;
                ++i;
            }
            ans += to_string(count) + ch;
        }
        return ans;
    }
};