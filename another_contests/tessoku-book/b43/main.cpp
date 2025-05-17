#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<int> ans(n + 1, m);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        ans[a]--;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    
}
