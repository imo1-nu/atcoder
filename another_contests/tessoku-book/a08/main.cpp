#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int h, w;
    cin >> h >> w;
    vector<vector<int>> x(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> x[i][j];
        }
    }
    vector<vector<int>> s(h + 1, vector<int>(w + 1));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + x[i][j];
        }
    }

    int q;
    cin >> q;
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        ans[i] = s[c + 1][d + 1] + s[a][b] - s[a][d + 1] - s[c + 1][b];
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
    /*for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << s[i + 1][j + 1];
            if (j < w - 1) cout << ' ';
        }
        cout << endl;
    }
    */
}
