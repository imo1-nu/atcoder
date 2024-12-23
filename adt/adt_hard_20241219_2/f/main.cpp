#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }

    int m = 0;
    for (int i = 0; i < N; ++i) {
        m = max(m, B[i] - A[i]);
    }
    vector<ll> S(N + 1);
    for (int i = 1; i <= N; ++i) {
        S[i] = S[i - 1] + A[i - 1];
    }

    cout << S[N] + m << endl;
}
