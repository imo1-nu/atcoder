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
    vector<int> A(N), B(N), C(M), D(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < M; i++) cin >> C[i];
    for (int i = 0; i < M; i++) cin >> D[i];
    vector<tuple<int, int, int>> T(N + M);
    for (int i = 0; i < N; i++) T[i] = {A[i], B[i], 0};
    for (int i = 0; i < M; i++) T[N + i] = {C[i], D[i], 1};
    sort(T.rbegin(), T.rend());
    
    multiset<int> S;
    for (int i = 0; i < N + M; i++) {
        int a, b, c;
        tie(a, b, c) = T[i];
        if (c == 1) {
            S.insert(b);
            continue;
        }
        auto it = S.lower_bound(b);
        if (it == S.end()) {
            cout << "No" << endl;
            return 0;
        }
        S.erase(it);
    }
    cout << "Yes" << endl;
}
