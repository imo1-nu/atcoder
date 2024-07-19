#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, K;
    cin >> N >> K;
    ll A, sum = 0;
    vector<bool> B(K + 1, false);
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (A <= K && B[A] == false) {
            sum += A;
            B[A] = true;
        }
    }

    ll ans = K * (K + 1) / 2 - sum;

    cout << ans << endl;
}
