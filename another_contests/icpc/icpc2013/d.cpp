#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int dir = 0;
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {1, 0, -1, 0};
    while (1) {
        int m, n;
        cin >> m >> n;

        int x = 0, y = 0;
        int mnx = 0;
        int mny = 0;
        int mxx = 0;
        int mxy = 0;
        map<pair<int, int>, int> mp;
        for (int i = 1; i < m; i++) {
            mnx
            mp[{x, y}] = i;
            if (!mp.count({x + dx[(dir + 1) % 4], y + dy[(dir + 1) % 4]}) && i != 1) dir = (dir + 1) % 4;
            x = x + dx[dir];
            y = y + dy[dir];
        }
    }
}
