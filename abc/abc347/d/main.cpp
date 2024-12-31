#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int a, b;
    ll C;
    cin >> a >> b >> C;

    int c = __builtin_popcountll(C);
    if (a + b < c || b + c < a || c + a < b || a + b + c > 120 || (a + b - c) % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }

    ll X = 0, Y = 0;
    queue<int> zero;
    for (int i = 0; i < 60; i++) {
        if (((C >> i) & 1) && a > b && a > 0) {
            X |= 1ll << i;
            a--;
        }
        else if ((C >> i) & 1 && b > 0) {
            Y |= 1ll << i;
            b--;
        }
        else if (!((C >> i) & 1)) {
            zero.push(i);
        }
    }

    while (a > 0) {
        int i = zero.front();
        zero.pop();
        X |= 1ll << i;
        Y |= 1ll << i;
        a--;
    }

    cout << X << " " << Y << endl;
}
