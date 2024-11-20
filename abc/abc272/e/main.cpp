#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<ll>> vals(M + 1);
    for (ll i = 0; i < N; i++) {
        if (A[i] >= N) continue;
        int l, r;
        if (A[i] >= 0) l = 0;
        else l = (-A[i] + i) / (i + 1);
        r = min(M + 1, (N - A[i] + i) / (i + 1));
        for (ll j = l; j < r; j++) {
            vals[j].push_back(A[i] + j * (i + 1));
        }
    }

    for (ll i = 1; i <= M; i++) {
        int size = vals[i].size();
        vector<bool> exi(size + 1);
        for (ll j = 0; j < size; j++) {
            if (vals[i][j] < size) exi[vals[i][j]] = true;
        }
        int ans = 0;
        while (exi[ans]) ans++;
        cout << ans << endl;
    }
}
