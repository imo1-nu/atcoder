#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N, M, L, Q;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++) cin >> B[i];
    cin >> L;
    vector<int> C(L);
    for (int i = 0; i < L; i++) cin >> C[i];

    vector<int> D(N * M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            D[i * M + j] = A[i] + B[j];
        }
    }
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());

    //for (int i = 0; i < N * M; i++) cout << D[i] << endl;

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x;
        bool ans = false;
        cin >> x;
        for (int j = 0; C[j] <= x && j < L; j++) {
            int l = 0, r = N * M, mid;
            while (l + 1 < r) {
                mid = (l + r) / 2;
                if (C[j] + D[mid] <= x) l = mid;
                else r = mid;
            }
            if (C[j] + D[l] == x) {
                ans = true;
                break;
            }
        }
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
