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
    sort(A.begin(), A.end());

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int idx = lower_bound(A.begin(), A.end(), A[i] * 2) - A.begin();
        ans += N - idx;
    }
    cout << ans << endl;
}
