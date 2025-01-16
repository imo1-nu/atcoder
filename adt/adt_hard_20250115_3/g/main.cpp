#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    multiset<int> S;
    for (int i = 0; i < N; i++) S.insert(A[i]);

    ll ans = 0;
    for (int i = 0; i < M; i++) {
        auto it = S.lower_bound(B[i]);
        if (it == S.end()) {
            ans = -1;
            break;
        }
        ans += *it;
        S.erase(it);
    }
    cout << ans << endl;
}
