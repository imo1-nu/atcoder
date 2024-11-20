#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> T(Q), X(Q), Y(Q);
    for (int i = 0; i < Q; i++) cin >> T[i] >> X[i] >> Y[i];
    int cnt = 0;
    for (int i = 0; i < Q; i++) {
        if (T[i] == 1) {
            swap(A[(X[i] - 1 - cnt + N) % N], A[(Y[i] - 1 - cnt + N) % N]);
        } else if (T[i] == 2) {
            cnt++;
            if (cnt == N) cnt = 0;
        } else {
            cout << A[(X[i] - 1 - cnt + N) % N] << endl;
        }
    }
}
