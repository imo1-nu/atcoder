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
    vector<int> P(N);
    multiset<int> S;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        S.insert(P[i]);
        ans += P[i];
    }
    sort(P.begin(), P.end());

    vector<pair<int, int>> C(M);
    for (int i = 0; i < M; i++) {
        cin >> C[i].second;
    }
    for (int i = 0; i < M; i++) {
        cin >> C[i].first;
        C[i].first *= -1;
    }
    sort(C.begin(), C.end());

    for (auto [d, l] : C) {
        auto itr = S.lower_bound(l);
        if (itr == S.end()) continue;
        ans += d;
        S.erase(itr);
    }

    cout << ans << endl;
}
