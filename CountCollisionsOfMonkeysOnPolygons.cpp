class Solution {
public:
    
    
        const int MOD = 1e9 + 7;
        int repeatedSquaring(int base, int exp) {
        int res = 1;
        while (exp > 0) {
            if (exp & 1) {
                res = (1ll * res * base) % MOD;
            }
            base = (1ll * base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
     long long int monkeyMove(int n) {
        return (repeatedSquaring(2, n) - 2 + MOD) % MOD;
    }
};