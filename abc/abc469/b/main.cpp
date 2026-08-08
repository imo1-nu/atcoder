#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') continue;
        if (i > 0 && S[i - 1] == 'o') continue;
        if (i < N - 1 && S[i + 1] == 'o') continue;
        ans++;
    }
    cout << ans << endl;
}
