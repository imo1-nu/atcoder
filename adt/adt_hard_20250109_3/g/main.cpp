#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll dist2(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector<tuple<int, int, int>> C;
    for (int i = 0; i < N; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        C.emplace_back(x, y, r);
    }

    atcoder::dsu D(N);
    int S = -1, T = -1;
    for (int i = 0; i < N; i++) {
        int x, y, r;
        tie(x, y, r) = C[i];
        if (dist2(sx, sy, x, y) == ll(r) * r) S = i;
        if (dist2(tx, ty, x, y) == ll(r) * r) T = i;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int x1, y1, r1, x2, y2, r2;
            tie(x1, y1, r1) = C[i];
            tie(x2, y2, r2) = C[j];
            ll d2 = dist2(x1, y1, x2, y2);
            if (d2 > ll(r1 + r2) * (r1 + r2) || d2 < ll(r1 - r2) * (r1 - r2)) continue;
            D.merge(i, j);
        }
    }

    if (D.same(S, T)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
