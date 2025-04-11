#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<mint> dp(N * M + 1, 0);
    int start = (N + 1) / 2 * (M + 1) / 2 - 1;
    dp[start] = 
}
