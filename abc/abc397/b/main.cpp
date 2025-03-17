#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < S.size(); i++) {
        if (ans % 2 == 0 && S[i] == 'o' || ans % 2 == 1 && S[i] == 'i') ans++;
        ans++;
    }
    if (ans % 2 == 1) ans++;
    cout << ans - S.size() << endl;
}
