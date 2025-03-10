#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N - 2; i++) {
        if (A[i] == A[i + 1] && A[i + 1] == A[i + 2]) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
}
