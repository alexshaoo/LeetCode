class Spreadsheet {
  vector<vector<int>> spreadsheet{26};
public:
  Spreadsheet(int rows) {
    for (int i = 0; i < 26; ++i) {
      vector<int> tmp(rows+1, 0);
      spreadsheet[i] = tmp;
    }
  }
  
  void setCell(string cell, int value) {
    int c = cell[0]-'A', r = stoi(cell.substr(1));
    // cout <<c << ' ' << r << '\n';
    spreadsheet[c][r] = value;
  }
  
  void resetCell(string cell) {
    int c = cell[0]-'A', r = stoi(cell.substr(1));
    spreadsheet[c][r] = 0;
  }
  
  int getValue(string formula) {
    int a = 0, b = 0;
    int l = 1, sz = 0;
    while (formula[l+sz] != '+') ++sz;
    if (formula[l] >= 'A' && formula[l] <= 'Z') {
      int c = formula[l]-'A', r = stoi(formula.substr(l+1, sz-1));
      a = spreadsheet[c][r];
    } else {
      a = stoi(formula.substr(l, sz));
    }
    l += sz+1;
    if (formula[l] >= 'A' && formula[l] <= 'Z') {
      int c = formula[l]-'A', r = stoi(formula.substr(l+1));
      b = spreadsheet[c][r];
    } else {
      b = stoi(formula.substr(l));
    }
    return a+b;
  }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */