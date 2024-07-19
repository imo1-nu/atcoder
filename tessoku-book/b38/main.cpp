#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    string s;
    cin >> n >> s;
    vector<int> right(n, 1), left(n, 1);

    for (int i = 1; i < n; i++) {
        if (s[i - 1] == 'A') right[i] = right[i - 1] + 1;
    }
    for (int i = n - 2; i > -1; i--) {
        if (s[i] == 'B') left[i] = left[i + 1] + 1;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(right[i], left[i]);
    }
    
    cout << ans << endl;
    
}
