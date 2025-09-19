class Spreadsheet {
  unordered_map<string, int> mp;
public:
  Spreadsheet(int rows) {}

  void setCell(string cell, int value) {
    mp[cell] = value;
  }
  
  void resetCell(string cell) {
    mp[cell] = 0;
  }
  
  int f(string s) {
    if (s[0] >= 'A' && s[0] <= 'Z') {
      if (mp.count(s)) return mp[s];
      return 0;
    }
    return stoi(s);
  }

  int getValue(string formula) {
    auto idx = formula.find('+');
    string s = formula.substr(1, idx-1), t = formula.substr(idx+1);
    return f(s)+f(t);
  }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */