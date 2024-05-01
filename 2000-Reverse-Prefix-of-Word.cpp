class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto it = word.find(ch);
        if (it != string::npos) reverse(word.begin(), word.begin() + it + 1);
        return word;
    }
};