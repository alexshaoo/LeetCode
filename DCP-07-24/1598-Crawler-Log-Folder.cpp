class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (const auto& log : logs) {
            if (log == "../") --depth;
            else if (log != "./") ++depth;
            depth = max(0, depth);
        }
        return depth;
    }
};