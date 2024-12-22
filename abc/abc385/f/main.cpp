#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> X(N), H(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> H[i];
    }

    double ans = 0;
    bool ok = false;
    for (int i = 0; i < N - 1; ++i) {
        ll x1 = X[i], y1 = H[i];
        ll x2 = X[i + 1], y2 = H[i + 1];
        double b = (x2 * y1 - x1 * y2) / (double)(x2 - x1);
        ans = max(ans, b);
        if (b >= 0) ok = true;
    }
    if (!ok) cout << -1 << endl;
    else cout << fixed << setprecision(18) << ans << endl;
}
