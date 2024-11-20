#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int d, n;
    cin >> d >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    vector<int> ans(d + 1, 24);
    for (int i = 0; i < n; i++) {
        for (int j = a[i][0]; j <= a[i][1]; j++) {
            ans[j] = min(ans[j], a[i][2]);
        }
    }
    
    int cnt = 0;
    for (int i = 1; i <= d; i++) {
        cnt += ans[i];
    }
    cout << cnt << endl;
}
