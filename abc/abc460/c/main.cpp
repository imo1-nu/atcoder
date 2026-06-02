#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (auto& a : A) cin >> a;
    for (auto& b : B) cin >> b;
    sort(B.begin(), B.end());
    multiset<int> S;
    for (auto a : A) S.insert(a * 2);

    int ans = 0;
    for (auto b : B) {
        auto itr = S.lower_bound(b);
        if (itr == S.end()) break;
        S.erase(itr);
        ans++;
    }
    cout << ans << endl;
}
