#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int a, b;
    cin >> a >> b;
    cout << gcd(max(a, b), min(a, b)) << endl;
}
