#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, max = 0;
    cin >> N >> M;
    vector<int> A(M), cnt(N);
    vector<string> S(N);
    for (int i = 0; i < M; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) cin >> S.at(i);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] == 'o') cnt[i] += A[j];
        }
        cnt[i] += i + 1;
        if (cnt[i] > max) max = cnt[i];
    }

    sort(A.rbegin(), A.rend());
    vector<int> B(M + 1);
    for (int i = 1; i <= M; i++) B[i] = B[i - 1] + A[i - 1];

    for (int i = 0; i < N; i++) {
        int j;
        for (j = 0; j < M + 1; j++) {
            if (cnt[i] + B[j] >= max) break;
        }
        cout << j << endl;
    }
}
