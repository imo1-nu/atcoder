#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[i] = i;
    }
    
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int b, x, y;
        cin >> b >> x >> y;
        x--;
        y--;
        if (b == 1) {
            swap(pos[x], pos[y]);
        }
        else {
            cout << a[pos[x]][y] << endl;
        }
    }
    
}
