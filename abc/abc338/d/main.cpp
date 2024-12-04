#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll op(ll a, ll b) { return min(a, b); }
ll e() { return 1e18; }
ll mapping(ll f, ll x) { return f + x; }
ll composition(ll f, ll g) { return f + g; }
ll id() { return 0; }

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    for (int i = 0; i < M; i++) {
        cin >> X[i];
        X[i]--;
    }

    atcoder::lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(N);
    for (int i = 0; i < N; i++) {
        seg.set(i, 0);
    }
    for (int i = 0; i < M - 1; i++) {
        ll l = X[i], r = X[i + 1];
        if (l > r) swap(l, r);
        seg.apply(0, l, r - l);
        seg.apply(l, r, N - r + l);
        seg.apply(r, N, r - l);
    }
    
    ll ans = seg.all_prod();
    cout << ans << endl;
}
