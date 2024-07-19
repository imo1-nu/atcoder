#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, i, ans = 1;
    cin >> N;
    vector<int> A(N);
    cin >> A[0];
    for (i = 1; i < N; i++) {
        cin >> A[i];
        if (A[i] != A[0]) {
            ans = 0;
            break;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
