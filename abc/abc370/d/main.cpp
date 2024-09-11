#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll H, W, Q;
    cin >> H >> W >> Q;
    vector<ll> R(Q), C(Q);
    for (ll i = 0; i < Q; i++) {
        cin >> R[i] >> C[i];
        R[i]--; C[i]--;
    }

    vector<set<ll>> row(H), col(W);
    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    
    for (ll i = 0; i < Q; i++) {
        if (row[R[i]].count((C[i]))) {
            row[R[i]].erase(C[i]);
            col[C[i]].erase(R[i]);
            continue;
        }

        auto itr = col[C[i]].lower_bound(R[i]);
        if (itr != col[C[i]].end()) {
            row[*itr].erase(C[i]);
            col[C[i]].erase(*itr);
        }

        itr = col[C[i]].lower_bound(R[i]);
        if (itr != col[C[i]].begin()) {
            itr--;
            row[*itr].erase(C[i]);
            col[C[i]].erase(*itr);
        }

        itr = row[R[i]].lower_bound(C[i]);
        if (itr != row[R[i]].end()) {
            col[*itr].erase(R[i]);
            row[R[i]].erase(*itr);
        }

        itr = row[R[i]].lower_bound(C[i]);
        if (itr != row[R[i]].begin()) {
            itr--;
            col[*itr].erase(R[i]);
            row[R[i]].erase(*itr);
        }
    }

    ll ans = 0;
    for (ll i = 0; i < H; i++) {
        ans += row[i].size();
    }
    cout << ans << endl;
}
