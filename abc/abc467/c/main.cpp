#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N - 1);
    for (auto& a : A) cin >> a;
    for (auto& b : B) cin >> b;
    ll odd = 0, even = 0;
    if (A[0] % 2 == 0) odd++;
    else even++;
    for (int i = 1; i < N; i++) {
        if (A[i] % 2 == 0 && B[i - 1] == 0) {
            odd++;
        }
        else if (A[i] % 2 == 0) {
            ll tmp = odd;
            odd = even + 1;
            even = tmp;
        }
        else if (B[i - 1] == 0) {
            even++;
        }
        else {
            ll tmp = odd;
            odd = even;
            even = tmp + 1;
        }
    }
    cout << min(odd, even) << endl;
}
