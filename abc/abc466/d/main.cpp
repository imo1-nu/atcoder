#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    map<int, int> r, c;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        r.erase(c[y]);
        c.erase(r[x]);
        r[x] = y;
        c[y] = x;
    }
    r.erase(0);
    cout << (int)r.size() << endl;
}
