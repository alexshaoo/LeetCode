#define ll long long
class Solution {
public:
    const int MOD = 1e9+7;
    ll modpow(ll base, ll exp) {
        ll ans = 1;
        while (exp > 0) {
            if (exp & 1) {
                ans = (ans * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return ans;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int currPow = 1;
        while (n > 0) {
            if (n & 1) powers.push_back(currPow);
            currPow *= 2;
            n >>= 1;
        }
        vector<ll> mulP = {1};
        for (int i = 0; i < powers.size(); ++i) {
            mulP.push_back((mulP[i] * (ll)powers[i]) % MOD);
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i) {
            ll start = mulP[queries[i][0]];
            ll end = mulP[queries[i][1]+1];
            if (start == 1) ans.push_back(end);
            else {
                ll inv = modpow(start, MOD-2);
                ans.push_back((end*inv) % MOD);
            }
        }
        return ans;
    }
};