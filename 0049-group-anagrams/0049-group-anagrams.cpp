class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagrams;
    for (const auto& str : strs) {
      string sortedStr = str;
      sort(sortedStr.begin(), sortedStr.end());
      anagrams[sortedStr].push_back(str);
    }
    
    vector<vector<string>> out;
    
    for (const auto& anagram : anagrams) {
      out.push_back(anagram.second);
    }
    
    return out;
  }
};