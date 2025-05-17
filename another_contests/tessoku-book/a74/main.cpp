#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> x(n + 1), y(n + 1);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (a != 0) {
                x[i] = a;
                y[j] = a;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (x[i] > x[j]) ans++;
            if (y[i] > y[j]) ans++;
        }
    }
    cout << ans << endl;
}
