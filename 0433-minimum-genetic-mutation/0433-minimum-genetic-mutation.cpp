class Solution {
public:
  bool diff(string s1, string s2) {
    int c = 0;
    for (int i = 0; i < 8; ++i) {
      if (s1[i] != s2[i]) {
        ++c;
      }
    }
    return (c == 1);
  }
  
  int minMutation(string start, string end, vector<string>& bank) {
    if (start == end) {
      return 0;
    }
    
    queue<pair<string, int>> q;
    q.push({ start, 0 });
    
    unordered_map<string, bool> mp;
    mp[start] = true;
    
    while (!q.empty()) {
      pair<string, int> p = q.front();
      q.pop();
      
      for (const auto& s : bank) {
        // string hasn't been seen, eliminates loops
        if (mp.find(s) == mp.end() && diff(p.first, s)) {
          if (s == end) {
            return 1 + p.second;
          }
          q.push({ s, 1 + p.second });
          mp[s] = true;
        }
      }
    }
    
    return -1;
  }
};