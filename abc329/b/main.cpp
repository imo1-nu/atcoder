#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, i;
    cin >> N;
    vector<int> A(N);
    for (i = 0; i < N; i++) cin >> A[i];
    sort(A.rbegin(), A.rend());
    for (i = 1; i < N; i++) {
        if (A[i] != A[0]) break;
    }
    cout << A[i] << endl;
}
