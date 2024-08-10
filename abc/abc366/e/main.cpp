#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, D;
    cin >> N >> D;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        X[i] += 2000000;
        Y[i] += 2000000;
    }
    vector<ll> Sx(4000001, 0), Sy(4000001, 0);
    for (int i = 0; i < N; i++) {
        Sx[X[i]]++;
        Sy[Y[i]]++;
    }
    for (int i = 1; i < 4000001; i++) {
        Sx[i] += Sx[i-1];
        Sy[i] += Sy[i-1];
    }

    vector<ll> Dx(4000001, 0), Dy(4000001, 0);
    for (int i = 0; i < N; i++) {
        Dx[0] += X[i];
        Dy[0] += Y[i];
    }
    for (int i = 1; i < 4000001; i++) {
        Dx[i] = Dx[i-1] - (Sx[4000000] - Sx[i-1]) + Sx[i-1];
        Dy[i] = Dy[i-1] - (Sy[4000000] - Sy[i-1]) + Sy[i-1];
    }
    sort(Dy.begin(), Dy.end());
    ll ans = 0;
    for (int i = 0; i < 4000001; i++) {
        ll y = D - Dx[i];
        auto itr = upper_bound(Dy.begin(), Dy.end(), y);
        ans += itr - Dy.begin();
    }
    cout << ans << endl;
}
