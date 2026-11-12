#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// https://github.com/imo1-nu/atcoder/tree/main/lib

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) A[i] = i + 1;

    while (Q--) {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) A[i] *= -1;
        for (int i = 0; i < k / 2; i++) swap(A[i], A[k - i - 1]);
    }

    for (auto a : A) cout << a << endl;
}
