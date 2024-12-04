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
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<ll> dp1(N, 1e18);
    dp1[1] = A[0];
    for (int i = 2; i < N; i++) {
        dp1[i] = min(dp1[i - 2], dp1[i - 1]) + A[i - 1];
    }

    vector<ll> dp2(N, 1e18);
    dp2[0] = A[N - 1];
    dp2[1] = dp2[0] + A[0];
    for (int i = 2; i < N; i++) {
        dp2[i] = min(dp2[i - 2], dp2[i - 1]) + A[i - 1];
    }

    cout << min(dp1[N - 1], min(dp2[N - 1], dp2[N - 2])) << endl;
}
