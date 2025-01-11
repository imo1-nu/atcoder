#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int Q;
    cin >> Q;
    vector<int> L(Q), R(Q);
    for (int i = 0; i < Q; i++) {
        cin >> L[i] >> R[i];
    }
}
