#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// https://github.com/imo1-nu/atcoder/tree/main/lib

struct point {
    int x, y;
};

long long cross(const point &a, const point &b) {
    return (long long) a.x * b.y - (long long) a.y * b.x;
}

bool cmp(const point &a, const point &b) {
    int ah = (a.y < 0 or (a.y == 0 and a.x < 0));
    int bh = (b.y < 0 or (b.y == 0 and b.x < 0));
    if (ah != bh) return ah < bh;
    return cross(a, b) > 0;
}

void argument_sort(vector<point> &points) {
    sort(points.begin(), points.end(), cmp);
}


void solve() {
    int N;
    cin >> N;
    vector<point> P(N);
    for (int i = 0; i < N; i++) cin >> P[i].x >> P[i].y;
    argument_sort(P);
    for (int i = 0; i < N; i++) P.push_back(P[i]);

    int r = 0;
    int ans = 0;
    for (int l = 0; l < N; l++) {
        if (l == r) r++;
        while (cross(P[l], P[r]) > 0) {
            r++;
        }
        // cout << r - l - 1 << endl;
        ans = max(ans, r - l);
    }
    cout << ans << endl;
    // cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) solve();
}
