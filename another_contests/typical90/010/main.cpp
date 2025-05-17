#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N;
    vector<int> C(N), P(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i] >> P[i];
    }
    cin >> Q;
    vector<int> L(Q), R(Q);
    for (int i = 0; i < Q; i++) {
        cin >> L[i] >> R[i];
    }
    
    vector<int> sum1(N + 1), sum2(N + 1);
    for (int i = 0; i < N; i++) {
        if (C[i] == 1) {
            sum1[i + 1] = sum1[i] + P[i];
            sum2[i + 1] = sum2[i];
        }
        else {
            sum1[i + 1] = sum1[i];
            sum2[i + 1] = sum2[i] + P[i];
        }
    }
    for (int i = 0; i < Q; i++) {
        cout << sum1[R[i]] - sum1[L[i] - 1] << " " << sum2[R[i]] - sum2[L[i] - 1] << endl;
    }
    
}
