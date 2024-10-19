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
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // for (int i = 0; i < N; i++) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < N - 1; i++) {
    //     cout << B[i] << " ";
    // }
    // cout << endl;
    
    

    bool ok = true;
    int a = N - 1;
    vector<bool> used(N);
    for (int b = N - 2; b >= 0; b--) {
        while (a >= 0 && A[a] > B[b]) {
            a--;
        }
        if (a < 0) {
            ok = false;
            break;
        }
        used[a] = true;
        a--;
    }
    
    if (ok) {
        int i;
        for (i = 0; i < N; i++) {
            if (!used[i]) {
                break;
            }
        }
        cout << A[i] << endl;
    }
    else {
        cout << -1 << endl;
    }
}
