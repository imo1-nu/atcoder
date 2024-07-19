#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    cout << n / 3 + n / 5 + n / 7 - n / 15 - n / 35 - n / 21 + n / 105 << endl;
}
