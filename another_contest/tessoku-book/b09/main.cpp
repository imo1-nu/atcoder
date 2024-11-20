#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<vector<int>> pos(1501, vector<int>(1501));
    vector<vector<int>> s(1502, vector<int>(1502));
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        pos[a][b]++;
        pos[a][d]--;
        pos[c][b]--;
        pos[c][d]++;
    }

    for (int i = 1; i < 1502; i++) {
        for (int j = 1; j < 1502; j++) {
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + pos[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (int i = 1; i < 1502; i++) {
        for (int j = 1; j < 1502; j++) {
            if(s[i][j] > 0) ans++;
        }
    }
    cout << ans << endl;
}
