#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, ans = 0;
    cin >> n;
    vector<char> t(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i];
        if (t[i] == '+') ans = (ans + a[i]) % 10000;
        if (t[i] == '-') ans = (ans - a[i] + 10000) % 10000;
        if (t[i] == '*') ans = (ans * a[i]) % 10000;
        
        cout << ans << endl;
    }
}
