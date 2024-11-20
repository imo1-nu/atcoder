#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, q;
    cin >> n;
    vector<vector<int>> pos(1501, vector<int>(1501));
    vector<vector<int>> s(1502, vector<int>(1502));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pos[x][y]++;
    }
    cin >> q;
    for (int i = 1; i < 1502; i++) {
        for (int j = 1; j < 1502; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + pos[i - 1][j - 1];
        }
    }
    
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << s[c + 1][d + 1] - s[a][d + 1] - s[c + 1][b] + s[a][b] << endl;
    }
    
}
