#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += (ll)abs(A[i] - B[i]);
    }
    if (cnt <= K && (K - cnt) % 2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
