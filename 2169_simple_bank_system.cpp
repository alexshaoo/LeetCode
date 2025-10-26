class Bank {
  size_t n;
  vector<long long> accs;
  bool oob(int accNum) { return accNum < 1 || accNum > n; }
public:
  Bank(vector<long long>& balance) : n{balance.size()}, accs{balance} {} 
  
  bool transfer(int account1, int account2, long long money) {
    if (oob(account2)) return false;
    return withdraw(account1, money) && deposit(account2, money);
  }
  
  bool deposit(int account, long long money) {
    if (oob(account)) return false;
    accs[account-1] += money;
    return true;
  }
  
  bool withdraw(int account, long long money) {
    if (oob(account) || money > accs[account-1]) return false;
    accs[account-1] -= money;
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