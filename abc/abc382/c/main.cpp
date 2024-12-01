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

    vector<int> pos(200001, N + 1);
    for (int i = 0; i < N; i++) pos[A[i]] = min(pos[A[i]], i + 1);
    for (int i = 1; i <= 200000; i++) pos[i] = min(pos[i], pos[i - 1]);
    for (int i = 0; i < M; i++) {
        if (pos[B[i]] == N + 1) cout << -1 << endl;
        else cout << pos[B[i]] << endl;
    }
}
