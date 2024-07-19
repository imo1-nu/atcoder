#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<vector<int>> x(n, vector<int> (m));
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x[i][j];
            b[j] += x[i][j];
        }
    }

    bool ans = true;
    for (int i = 0; i < m; i++) {
        if (a[i] > b[i]) ans = false;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
