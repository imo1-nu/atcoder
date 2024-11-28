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
    vector<int> H(N), W(M);
    for (int i = 0; i < N; i++) cin >> H[i];
    for (int i = 0; i < M; i++) cin >> W[i];
    sort(H.begin(), H.end());
    sort(W.begin(), W.end());

    vector<ll> left(N), right(N);
    for (int i = 2; i < N; i += 2) {
        left[i] = left[i - 2] + H[i - 1] - H[i - 2];
        left[i - 1] = left[i - 2];
    }

    for (int i = N - 3; i >= 0; i -= 2) {
        right[i] = right[i + 2] + H[i + 2] - H[i + 1];
        right[i + 1] = right[i + 2];
    }

    ll ans = 1e18;
    for (int i = 0; i < N; i++) {
        int idx = lower_bound(W.begin(), W.end(), H[i]) - W.begin();
        if (idx > 0 && abs(H[i] - W[idx - 1]) < abs(H[i] - W[idx]) || idx == M) {
            idx--;
        }
        ll tmp = left[i] + right[i] + abs(H[i] - W[idx]);
        if (i % 2 == 1) {
            tmp += H[i + 1] - H[i - 1];
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
