#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<int> cnt(M);
    for (int i = 0; i < N; i++) {
        cnt[A[i]]++;
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            if (cnt[j] == 0) {
                cout << N - i - 1 << endl;
                return 0;
            }
        }
        cnt[A[i]]--;
    }
    cout << N << endl;
}
