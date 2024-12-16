#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    ll L;
    cin >> N >> L;
    vector<int> A(N);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        L -= A[i];
        pq.push(A[i]);
    }
    
    if (L > 0) pq.push(L);

    ll ans = 0;
    while (pq.size() > 1) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    cout << ans << endl;
}
