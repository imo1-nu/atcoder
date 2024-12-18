#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint1000000007;

#define INF INT_MAX / 2

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

    vector<pair<int, int>> P(N);
    for (int i = 0; i < N; ++i) {
        P[i] = {abs(A[i]), A[i]};
    }
    sort(P.rbegin(), P.rend());

    int cnt = 0;
    mint ans = 1;
    for (int i = 0; i < K; ++i) {
        ans *= P[i].second;
        if (P[i].second < 0) ++cnt;
    }

    if (cnt % 2 == 1) {
        int m1 = INF, p1 = INF;
        for (int i = 0; i < K; ++i) {
            if (P[i].second < 0) m1 = P[i].second;
        }
        for (int i = K; i < N; ++i) {
            if (P[i].second >= 0) {
                p1 = P[i].second;
                break;
            }
        }
        bool ok1 = (m1 != INF && p1 != INF);

        int p2 = INF, m2 = INF;
        for (int i = 0; i < K; ++i) {
            if (P[i].second > 0) p2 = P[i].second;
        }
        for (int i = K; i < N; ++i) {
            if (P[i].second <= 0) {
                m2 = P[i].second;
                break;
            }
        }
        bool ok2 = (p2 != INF && m2 != INF);
        if (ok1 && ok2) {
            if (1ll * m1 * m2 < 1ll * p1 * p2) ans = ans * p1 / m1;
            else ans = ans * m2 / p2;
        }
        else if (ok1) ans = ans * p1 / m1;
        else if (ok2) ans = ans * m2 / p2;
        else {
            ans = 1;
            for (int i = 0; i < K; ++i) {
                ans *= P[N - 1 - i].second;
            }
        }
    }

    cout << ans.val() << endl;
}
