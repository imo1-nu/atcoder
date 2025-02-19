#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int Ax, Ay, Bx, By;
    cin >> Ax >> Ay >> Bx >> By;
    int N;
    cin >> N;
    vector<int> X(N + 1), Y(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    X[N] = X[0];
    Y[N] = Y[0];

    auto cross = [&](int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) -> bool {
        ll S1 = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
        ll S2 = (x2 - x1) * (y4 - y1) - (y2 - y1) * (x4 - x1);
        ll S3 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
        ll S4 = (x4 - x3) * (y2 - y3) - (y4 - y3) * (x2 - x3);
        return S1 * S2 < 0 && S3 * S4 < 0;
    };

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (cross(Ax, Ay, Bx, By, X[i], Y[i], X[i + 1], Y[i + 1])) {
            cnt++;
        }
    }
    cout << cnt / 2 + 1 << endl;
}
