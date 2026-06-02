#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void solve() {
    pair<ll, ll> X, Y, R;
    cin >> X.first >> Y.first >> R.first >> X.second >> Y.second >> R.second;
    ll dist1 = (X.first - X.second) * (X.first - X.second) + (Y.first - Y.second) * (Y.first - Y.second);
    ll dist2 = (R.first + R.second) * (R.first + R.second);
    if (dist1 <= dist2 && dist1 >= (R.first - R.second) * (R.first - R.second)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) solve();
}
