#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int X, Y;
    cin >> X >> Y;
    int cnt = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i + j >= X || abs(i - j) >= Y) cnt++;
        }
    }
    cout << fixed << setprecision(12) << static_cast<double>(cnt) / 36.0 << endl;
}
