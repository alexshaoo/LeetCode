class Solution {
public:
    int maximum69Number(int num) {
        string ans = to_string(num);
        for (char& digit : ans) {
            if (digit == '6') {
                digit = '9';
                return stoi(ans);
            }
        }
        return num;
    }
};