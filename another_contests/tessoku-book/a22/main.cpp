#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);

    for (ll i = 0; i < n - 1; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
        b[i]--;
    }
    
    vector<ll> score(n, -1e9);
    score[0] = 0;
    for (ll i = 0; i < n - 1; i++) {
        score[a[i]] = max(score[a[i]], score[i] + 100);
        score[b[i]] = max(score[b[i]], score[i] + 150);
    }
    cout << score[n - 1] << endl;
}
