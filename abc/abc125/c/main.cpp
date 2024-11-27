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
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> L(N), R(N);
    for (int i = 1; i < N; i++) {
        L[i] = gcd(L[i - 1], A[i - 1]);
    }

    for (int i = N - 2; i >= 0; i--) {
        R[i] = gcd(R[i + 1], A[i + 1]);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, gcd(L[i], R[i]));
    }
    cout << ans << endl;
}
