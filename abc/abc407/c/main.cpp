#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    int ans = S.length();
    int prev = 0;
    for (int i = S.length() - 1; i >= 0; i--) {
        ans += ((S[i] - '0') - prev + 10) % 10;
        prev = S[i] - '0';
    }
    cout << ans << endl;
}
