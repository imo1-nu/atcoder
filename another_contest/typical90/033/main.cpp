#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W;
    cin >> H >> W;
    if (H == 1 || W == 1) cout << H * W << endl;
    else cout << ((H + 1) / 2) * ((W + 1) / 2) << endl;
}
