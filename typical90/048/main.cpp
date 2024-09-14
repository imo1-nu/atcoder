#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<ll> A(2 * N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        A.push_back(b);
        A.push_back(a - b);
    }
    sort(A.rbegin(), A.rend());
    ll ans = 0;
    for (int i = 0; i < K; ++i) ans += A[i];
    cout << ans << endl;
}
