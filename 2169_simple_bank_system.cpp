class Bank {
  int n;
  vector<long long> accs;
  bool oob(int accNum) {
    return accNum < 1 || accNum > n;
  }
public:
  Bank(vector<long long>& balance) {
    n = balance.size();
    accs.reserve(n+1);
    for (int i = 0; i < n; ++i) accs[i+1] = balance[i];
  }
  
  bool transfer(int account1, int account2, long long money) {
    if (oob(account1) || oob(account2) || money > accs[account1]) return false;
    accs[account2] += money;
    accs[account1] -= money;
    return true;
  }
  
  bool deposit(int account, long long money) {
    if (oob(account)) return false;
    accs[account] += money;
    return true;
  }
  
  bool withdraw(int account, long long money) {
    if (oob(account)) return false;
    if (money > accs[account]) return false;
    accs[account] -= money;
    return true;
  }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */