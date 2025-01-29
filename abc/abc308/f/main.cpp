#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    multiset<int> P;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        P.insert(p);
        ans += p;
    }
    vector<pair<int, int>> C(M);
    for (int i = 0; i < M; i++) cin >> C[i].second;
    for (int i = 0; i < M; i++) cin >> C[i].first;
    sort(C.rbegin(), C.rend());

    for (auto [d, l] : C) {
        auto it = P.lower_bound(l);
        if (it == P.end()) continue;
        ans -= d;
        P.erase(it);
    }
    cout << ans << endl;
}
