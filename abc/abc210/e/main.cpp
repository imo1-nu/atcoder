#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<pair<ll, int>> P(M);
    for (int i = 0; i < M; i++) {
        cin >> P[i].second >> P[i].first;
    }
    sort(P.begin(), P.end());
    int g_sum = N;
    ll ans = 0;
    for (int i = 0; i < M; i++) {
        int d = g_sum - gcd(g_sum, P[i].second);
        ans += P[i].first * d;
        g_sum = gcd(g_sum, P[i].second);
    }
    if (g_sum == 1) cout << ans << endl;
    else cout << -1 << endl;
}
