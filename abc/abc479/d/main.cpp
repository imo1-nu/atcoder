#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;

    vector<int> L(N), R(N);
    L[0] = R[N - 1] = 2e9;
    for (int i = 1; i < N; i++) cin >> L[i];
    for (int i = 0; i < N - 1; i++) cin >> R[i];

    vector<int> minL(N), minR(N);
    minL[N - 1] = L[N - 1];
    minR[0] = R[0];
    for (int i = N - 2; i >= 0; i--) minL[i] = min(minL[i + 1], L[i]);
    for (int i = 1; i < N; i++) minR[i] = min(minR[i - 1], R[i]);

    while (Q--) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        int ans = 2e9;
        if (s < t) {
            if (s == 0) ans = R[s];
            else ans = min(R[s], L[s] + minR[s - 1]);
        }
        else {
            if (s == N - 1) ans = L[s];
            else ans = min(L[s], R[s] + minL[s + 1]);
        }
        cout << ans << endl;
    }
}
