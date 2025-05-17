#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vector<ll> fib(n + 1);
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000007;
    }
    cout << fib[n] << endl;
}
