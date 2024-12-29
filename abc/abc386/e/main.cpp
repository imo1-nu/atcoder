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
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll sum = 0;
    if (K > N - K) {
        K = N - K;
        for (int i = 0; i < N; ++i) sum ^= A[i];
    }

    function<ll(int, int, ll)> dfs = [&](int i, int cnt, ll x) -> ll {
        if (cnt == K) return sum ^ x;
        if (i == N) return 0;
        return max(dfs(i + 1, cnt + 1, x ^ A[i]), dfs(i + 1, cnt, x));
    };

    cout << dfs(0, 0, 0) << endl;
}
