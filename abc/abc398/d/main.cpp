#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, R, C;
    cin >> N >> R >> C;
    string S;
    cin >> S;
    map<char, pair<int, int>> d;
    d['N'] = make_pair(-1, 0);
    d['W'] = make_pair(0, -1);
    d['S'] = make_pair(1, 0);
    d['E'] = make_pair(0, 1);
    set<pair<int, int>> kemuri;
    kemuri.insert({0, 0});
    int x = R, y = C;
    for (auto c : S) {
        x -= d[c].first;
        y -= d[c].second;
        kemuri.insert({x - R, y - C});
        if (kemuri.count({x, y})) cout << 1;
        else cout << 0;
    }
    cout << endl;
}
