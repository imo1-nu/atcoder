#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> L(N), S(N + 1);
    for (auto& l : L) cin >> l;
    for (int i = 1; i <= N; i++) S[i] = S[i - 1] + L[i - 1];
    int len = S[N];
    int ans = len;
    for (auto& s : S) {
        ans = min(ans, abs(len - 2 * s));
    }
    cout << ans << endl;
}
