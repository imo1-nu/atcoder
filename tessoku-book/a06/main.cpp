#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> S(N + 1);
    for (int i = 1; i <= N; i++) {
        S[i] = S[i - 1] + A[i - 1];
    }
    
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << S[r] - S[l - 1] << endl;
    }
    
}
