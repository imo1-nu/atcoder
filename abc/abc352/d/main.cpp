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
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    vector<int> A(N + 1);
    for (int i = 0; i < N; i++) A[P[i]] = i;
    set<int> S;
    for (int i = 1; i <= K; i++) S.insert(A[i]);
    int ans = *S.rbegin() - *S.begin();
    for (int i = 2; i <= N - K + 1; i++) {
        S.erase(A[i - 1]);
        S.insert(A[i + K - 1]);
        ans = min(ans, *S.rbegin() - *S.begin());
    }
    cout << ans << '\n';
}
