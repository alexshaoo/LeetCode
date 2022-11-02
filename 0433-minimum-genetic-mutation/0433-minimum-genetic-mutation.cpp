class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
      unordered_set<string> bankSet(bank.begin(), bank.end());
      if (bankSet.find(end) == bankSet.end()) return -1;
      queue<string> q;
      q.push(start);
      int depth = 0;
      while (!q.empty()) {
          int size = q.size();
          for (int i = 0; i < size; i++) {
              string curr = q.front();
              q.pop();
              if (curr == end) return depth;
              for (int j = 0; j < curr.size(); j++) {
                  char temp = curr[j];
                  for (char c : {'A', 'C', 'G', 'T'}) {
                      curr[j] = c;
                      if (bankSet.find(curr) != bankSet.end()) {
                          q.push(curr);
                          bankSet.erase(curr);
                      }
                  }
                  curr[j] = temp;
              }
          }
          depth++;
      }
      return -1;
    }
};