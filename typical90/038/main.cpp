#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll POW18 = 1000000000000000000ll;
    ll A, B;
    cin >> A >> B;
    if (A > B) swap(A, B);
    B /= GCD(A, B);
    if (B > POW18 / A) cout << "Large" << endl;
    else cout << A * B << endl;
}
