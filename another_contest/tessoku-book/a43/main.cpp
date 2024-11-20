#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    vector<char> b(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (b[i] == 'E') ans = max(ans, l - a[i]);
        else ans = max(ans, a[i]);
    }
    cout << ans << endl;
}
