#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    while (1) {
        ll N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }

        set<ll> A;
        for (int i = 0; i < N; i++) {
            ll a;
            cin >> a;
            if (a > M) continue;
            a--;
            A.insert(a);
        }
        ll sum = A.size();
        for (auto a : A) {
            if (a % 7 >= 5) sum--;
        }
        
        ll tmp = M / 7 * 2;
        if (M % 7 == 6) tmp++;
        M -= tmp;
        cout << M - sum << endl;
    }
}