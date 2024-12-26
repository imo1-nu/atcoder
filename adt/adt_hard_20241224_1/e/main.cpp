#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll ans = ll(K + 1) * K / 2;
    set<int> s;
    for (int i = 0; i < N; ++i) {
        if (A[i] <= K && !s.count(A[i])) {
            ans -= A[i];
            s.insert(A[i]);
        }
    }
    cout << ans << endl;
}
