#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    if (x > z && z > y || x < z && z < y) cout <<  "Yes" << endl;
    else cout <<  "No" << endl;
}
