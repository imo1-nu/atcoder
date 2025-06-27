#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    while (1) {
        int N;
        cin >> N;
        if (N == 0) break;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        int ans = *max_element(A.begin(), A.end());
        cout << ans << endl;
    }
}