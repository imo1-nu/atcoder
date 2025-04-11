#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string S, T;
    cin >> N >> S >> T;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] != T[i]) ans++;
    }
    cout << ans << endl;
}
