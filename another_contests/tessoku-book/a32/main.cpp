#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, a, b;
    cin >> n >> a >> b;
    vector<bool> dp(n + 1, false); //先行のターンでn個積んであるとき先行が勝利するか
    for (int i = 1; i <= n; i++) {
        if (i - a >= 0 && !dp[i - a]) dp[i] = true;
        if (i - b >= 0 && !dp[i - b]) dp[i] = true;
    }
    
    if (dp[n]) cout << "First" << endl;
    else cout << "Second" << endl;
}
