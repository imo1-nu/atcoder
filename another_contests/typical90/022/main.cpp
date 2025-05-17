#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll A, B, C;
    cin >> A >> B >> C;
    ll g = gcd(A, gcd(B, C));
    A /= g; B /= g; C /= g;
    cout << A + B + C - 3 << endl;
}
