#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void solve() {
    int N;
    string S;
    cin >> N >> S;
    vector<int> X(N), Y(N - 1);
    for (auto& x : X) cin >> x;
    for (auto& y : Y) cin >> y;

    pair<ll, ll> p = (S[0] == 'S' ? make_pair(0, -X[0]) : make_pair(-X[0], 0));

    for (int i = 1; i < N; i++) {
        auto np = p;
        np.first = max(p.first, p.second + Y[i - 1]) - (S[i] == 'S' ? 0 : X[i]);
        np.second = max(p.first, p.second) - (S[i] == 'R' ? 0 : X[i]);
        p = np;
    }
    cout << max(p.first, p.second) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) solve();
}
