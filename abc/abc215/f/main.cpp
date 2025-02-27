#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<pair<int, int>> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
    }
    sort(P.begin(), P.end());
    int l = 0, r = 1000000001;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        bool ok = false;
        int mn = 1000000001, mx = 0;
        int L = 0, R = 0;
        while (R < N) {
            while (L < R && P[R].first - P[L].first >= m) {
                mn = min(mn, P[L].second);
                mx = max(mx, P[L].second);
                L++;
            }
            if (P[R].second - m >= mn || P[R].second + m <= mx) ok = true;
            R++;
        }
        if (ok) l = m;
        else r = m;
    }
    cout << l << endl;
}
