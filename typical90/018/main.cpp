#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    double T, L, X, Y;
    cin >> T >> L >> X >> Y;
    ll Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int E;
        cin >> E;
        double y, z;
        y = -L / 2 * sin(2 * M_PI * E / T);
        z = L / 2 - L / 2 * cos(2 * M_PI * E / T);
        double dist = sqrt(X * X + (Y - y) * (Y - y));
        double ans = atan(z / dist) * 180 / M_PI;
        cout << fixed << setprecision(10) << ans << endl;
    }
    
}
