#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }

    if (sum % N != 0) {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] < sum / N) {
            cout << -1 << endl;
            return 0;
        }
        ans += A[i] - sum / N;
        A[i + 1] += A[i] - sum / N;
        A[i] = sum / N;
    }
    
    if (A[N - 1] != sum / N) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}
