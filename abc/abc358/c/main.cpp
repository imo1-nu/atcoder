#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    int ans = n;
    for (int i = 0; i < (1 << n); i++) {
        bitset<10> b = i;
        vector<bool> check(m, false);
        for (int j = 0; j < n; j++) {
            if (b.test(j)) {
                for (int k = 0; k < m; k++) {
                    if (s[j][k] == 'o') check[k] = true;
                }
            }
        }
        bool c = true;
        for (int j = 0; j < m; j++) {
            if (check[j] == false) c = false;
        }
        if (c) {
            int cnt = b.count();
            ans = min(ans, cnt);
        }
    }
    
    cout << ans << endl;
}
