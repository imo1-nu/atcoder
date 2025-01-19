#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll X;
    cin >> X;
    ll ans = 1, i;
    for (i = 1; ans < X; i++) {
        ans *= i;
    }
    cout << i - 1 << endl;
}
