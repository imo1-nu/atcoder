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
    
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll a = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        ll c = C.end() - upper_bound(C.begin(), C.end(), B[i]);
        ans += a * c;
    }

    cout << ans << endl;
}
