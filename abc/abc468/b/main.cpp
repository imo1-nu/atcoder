#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int M, D;
    string S;
    cin >> M >> D >> S;

    int ans = 0;
    for (int i = 0; i < M; i++) {
        bool ok = true;
        for (int j = max(0, i - D); j <= min(M - 1, i + D); j++) {
            if (S[j] == 'G') ok = false;
        }
        if (ok) ans++;
    }
    cout << ans << endl;
}
