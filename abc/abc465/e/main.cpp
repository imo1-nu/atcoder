#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    vector<int> N;
    for (auto c : S) N.push_back(c - '0');

    vector<vector<vector<vector<vector<vector<mint>>>>>> dp(N.size() + 1, vector<vector<vector<vector<vector<mint>>>>>(2, vector<vector<vector<vector<mint>>>>(3, vector<vector<vector<mint>>>(2, vector<vector<mint>>(1 << 10, vector<mint>(2, 0))))));
    dp[0][0][0][0][0][0] = 1;
    for (int i = 0; i < N.size(); i++) {
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int mod3 = 0; mod3 < 3; mod3++) {
                for (int seen3 = 0; seen3 < 2; seen3++) {
                    for (int used = 0; used < (1 << 10); used++) {
                        for (int not0 = 0; not0 < 2; not0++) {
                            for(int x = 0; x <= (smaller ? 9 : N[i]); x++){
                                dp[i + 1][smaller || x < N[i]][(mod3 + x) % 3][seen3 || x == 3][(used | (1 << x)) * (not0 || x)][not0 || x] += dp[i][smaller][mod3][seen3][used][not0];
                            }
                        }
                    }
                }
            }
        }
    }
    
    mint ans = 0;
    for (int used = 0; used < 1024; used++) {
        if (__builtin_popcount(used) == 3) continue;
        ans += dp[N.size()][0][0][0][used][1] + dp[N.size()][1][0][0][used][1];
    }
    for (int mod3 = 1; mod3 < 3; mod3++) {
        for (int used = 0; used < 1024; used++) {
            if (__builtin_popcount(used) == 3) continue;
            ans += dp[N.size()][0][mod3][1][used][1] + dp[N.size()][1][mod3][1][used][1];
        }
    }
    for (int mod3 = 1; mod3 < 3; mod3++) {
        for (int used = 0; used < 1024; used++) {
            if (__builtin_popcount(used) != 3) continue;
            ans += dp[N.size()][0][mod3][0][used][1] + dp[N.size()][1][mod3][0][used][1];
        }
    }
    cout << ans.val() << endl;
}
