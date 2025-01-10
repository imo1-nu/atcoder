#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<ll> S(N + 1);
    for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i - 1];
    while (Q--) {
        ll x;
        cin >> x;
        ll ans = 0;
        auto idx = lower_bound(A.begin(), A.end(), x) - A.begin();
        ans += x * idx - S[idx];
        ans += S[N] - S[idx] - x * (N - idx);
        cout << ans << endl;
    }
}
