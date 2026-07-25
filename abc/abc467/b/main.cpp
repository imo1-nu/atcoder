#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        if (s == "keep") ans += b - a;
    }
    cout << ans << endl;
}
