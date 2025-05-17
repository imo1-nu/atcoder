#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << a * b / gcd(a, b) << endl;
}
