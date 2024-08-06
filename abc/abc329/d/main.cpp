#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    vector<int> B(N, 0);
    for (int i = 0; i < M; i++) cin >> A[i];

    pair<int, int> max(0, 0);
    for (int i = 0; i < M; i++) {
        B[A[i] - 1]++;
        if (B[A[i] - 1] > max.first || B[A[i] - 1] == max.first && A[i] - 1 < max.second) {
            max.first = B[A[i] - 1];
            max.second = A[i] - 1;
        }
        cout << max.second + 1 << endl;
    }
}
