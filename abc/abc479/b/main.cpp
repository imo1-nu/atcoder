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
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            cnt++;
            ans = max(ans, cnt);
        }
        else cnt = 0;
    }
    cout << ans << endl;
}
