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
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    unordered_set<ll> S;
    function<void(int, int, ll) > dfs = [&](int cur, int sz, ll ans) {
        if (cur == N) {
            S.insert(ans);
            return;
        }
        for (int i = 0; i <= sz; i++) {
            ans ^= B[i];
            B[i] += A[cur];
            ans ^= B[i];
            if (i < sz) dfs(cur + 1, sz, ans);
            else dfs(cur + 1, sz + 1, ans);
            ans ^= B[i];
            B[i] -= A[cur];
            ans ^= B[i];
        }
    };

    dfs(0, 0, 0);
    cout << S.size() << endl;
}
