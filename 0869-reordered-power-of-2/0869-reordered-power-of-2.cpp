#define ARR array<int, 10>
class Solution {
public:
    struct HASH {
        size_t operator()(const ARR& a) const {
            size_t h = 0;
            for (int v : a) {
                auto ha = hash<int>{}(v);
                h ^= ha + 623324234234252325 + (h<<4) + (h<<6);
            }
            return h;
        }
    };
    ARR f(int n) {
        ARR nn{};
        while (n > 0) {
            nn[n%10]++;
            n /= 10;
        }
        return nn;
    }
    bool reorderedPowerOf2(int n) {
        unordered_set<ARR, HASH> s;
        for (int i = 1; i <= 1e9; i *= 2) {
            s.insert(f(i));
        }
        return s.contains(f(n));
    }
};