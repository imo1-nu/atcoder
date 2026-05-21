#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> C(N);
    for (auto& c : C) cin >> c;
    for (int i = 0; i < N; i++) {
        if (A + B == C[i]) cout << i + 1 << endl;
    }
}
