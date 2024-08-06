#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    int x, y;
    cin >> x >> y;
    x--; y--;
    for (int i = 0; i < h; i++) {
        cin >> c[i];
    }
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'L' && y > 0 && c[x][y - 1] == '.') {
            y--;
        } else if (s[i] == 'R' && y < w - 1 && c[x][y + 1] == '.') {
            y++;
        } else if (s[i] == 'U' && x > 0 && c[x - 1][y] == '.') {
            x--;
        } else if (s[i] == 'D' && x < h - 1 && c[x + 1][y] == '.') {
            x++;
        }
    }
    cout << x + 1 << " " << y + 1 << endl;
}
