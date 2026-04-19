#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> F(N);
    for (auto& f : F) cin >> f;
    vector<int> C(M);
    for (auto& f : F) C[f - 1]++;
    bool ans1 = true, ans2 = true;
    for (auto c : C) {
        if (c > 1) ans1 = false;
        if (c < 1) ans2 = false;
    }
    cout << (ans1 ? "Yes" : "No") << endl;
    cout << (ans2 ? "Yes" : "No") << endl;
}
