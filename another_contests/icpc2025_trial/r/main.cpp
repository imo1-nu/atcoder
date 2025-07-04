#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    while (1) {
        int N;
        cin >> N;
        if (N == 0) break;
        int idx = 0, d = 1e9;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            if (abs(A[i] - 2023) < d) {
                idx = i;
                d = abs(A[i] - 2023);
            }
        }
        cout << idx + 1 << endl;
    }
}