#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<unordered_set<int>> A(M);
    vector<vector<int>> C(N);
    for (int i = 0; i < M; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            int a;
            cin >> a;
            a--;
            A[i].insert(a);
            C[a].push_back(i);
        }
    }
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        B[i]--;
    }

    int ans = 0;
    for (int b : B) {
        for (int a : C[b]) {
            A[a].erase(b);
            if (A[a].empty()) ans++;
        }
        cout << ans << endl;
    }
}
