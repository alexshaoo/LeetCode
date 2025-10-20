class Solution {
public:
  int finalValueAfterOperations(vector<string>& operations) {
    unordered_map<string, int> mp;
    mp["--X"] = -1;
    mp["X--"] = -1;
    mp["++X"] = 1;
    mp["X++"] = 1;
    int x = 0;
    for (auto op : operations) x += mp[op];
    return x;
  }
};