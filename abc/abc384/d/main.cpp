#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N * 2);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
        A[i + N] = A[i];
    }

    vector<ll> sum(N * 2 + 1);
    for (ll i = 1; i <= N * 2; ++i) {
        sum[i] = sum[i - 1] + A[i - 1];
    }

    S %= sum[N];

    bool ans = false;
    for (int i = 0; i < N; ++i) {
        auto it = lower_bound(sum.begin(), sum.end(), sum[i] + S);
        if (*it == sum[i] + S) {
            ans = true;
            break;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
