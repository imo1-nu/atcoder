#include <bits/stdc++.h>
using namespace std;
using ll = long long;


using Graph = vector<vector<ll>>;
using T = tuple<ll, ll, ll>;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(m), b(m), s(m), t(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> s[i] >> b[i] >> t[i];
        t[i] += k;
    }
    
    vector<T> List;
    for (ll i = 0; i < m; i++) {
        List.push_back(T{s[i], i, 2});
        List.push_back(T{t[i], i, 1});
    }
    for (ll i = 0; i < n; i++) {
        List.push_back(T{-1, i, 0});
        List.push_back(T{2100000000, i, 0});
    }
    sort(List.begin(), List.end());
    
    
    
}
