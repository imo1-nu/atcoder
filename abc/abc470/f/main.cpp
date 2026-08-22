#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    string S;
    cin >> N >> M >> S;
    atcoder::dsu d(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        d.merge(a, b);
    }

    vector<mint> p(N + 1), pinv(N + 1);
    p[0] = pinv[0] = 1;
    for (int i = 1; i <= N; i++) {
        p[i] = p[i - 1] * i;
        pinv[i] = pinv[i - 1] / i;
    }

    bool same = false;
    mint ans = 1;
    for (auto v : d.groups()) {
        map<char, int> mp;
        for (auto x : v) mp[S[x]]++;
        ans *= p[v.size()];
        for (auto [_, cnt] : mp) {
            if (cnt > 1) same = true;
            ans *= pinv[cnt];
        }
    }
    if (!same) ans /= 2;
    cout << ans.val() << endl;
}
