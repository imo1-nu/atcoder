#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N), S(N), T(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) {
        cin >> S[i] >> T[i];
        A[i + 1] += A[i] / S[i] * T[i];
    }
    cout << A[N - 1] << endl;
}
