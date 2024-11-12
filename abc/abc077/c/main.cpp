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
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    vector<int> cntBtoA(N);
    for (int i = 0; i < N; i++) {
        cntBtoA[i] = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
    }
    vector<ll> cntBtoAsum(N + 1);
    for (int i = 1; i <= N; i++) {
        cntBtoAsum[i] = cntBtoAsum[i - 1] + cntBtoA[i - 1];
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int idx = lower_bound(B.begin(), B.end(), C[i]) - B.begin();
        ans += cntBtoAsum[idx];
    }

    cout << ans << endl;
}
