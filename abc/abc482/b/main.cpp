#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// https://github.com/imo1-nu/atcoder/tree/main/lib

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<string> S(5);
    for (auto& s : S) cin >> s;
    int ans = 5;
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        cnt = 0;
        for (int j = 0; j < 5; j++) {
            if (S[i][j] == '.') cnt++;
        }
        ans = min(ans, cnt);
    }
    for (int i = 0; i < 5; i++) {
        cnt = 0;
        for (int j = 0; j < 5; j++) {
            if (S[j][i] == '.') cnt++;
        }
        ans = min(ans, cnt);
    }

    cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (S[i][i] == '.') cnt++;
    }
    ans = min(ans, cnt);

    cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (S[i][4 - i] == '.') cnt++;
    }
    ans = min(ans, cnt);

    cout << ans << endl;
}
