#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    N--;
    vector<ll> pow10(19);
    pow10[0] = 1;
    for (int i = 1; i < 19; i++) {
        pow10[i] = pow10[i - 1] * 10;
    }
    for (int d = 1;; d++) {
        int x = (d + 1) / 2;
        if (N <= 9 * pow10[x - 1]) {
            string S = to_string(pow10[x - 1] + N - 1);
            S.resize(d, '#');
            for (int i = x; i < d; i++) {
                S[i] = S[d - i - 1];
            }
            cout << S << endl;
            return 0;
        }
        else {
            N -= 9 * pow10[x - 1];
        }
    }
}
