#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    int ans = 0;
    while (M != 0) {
        M = N % M;
        ans++;
    }
    cout << ans << endl;
}
