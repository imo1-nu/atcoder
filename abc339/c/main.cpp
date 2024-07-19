#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, min = 0;
    cin >> N;
    vector<long long> A(N), S(N + 1, 0);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
        if (S[i + 1] < min) min = S[i + 1];
    }
    cout << -min + S[N] << endl;
}
