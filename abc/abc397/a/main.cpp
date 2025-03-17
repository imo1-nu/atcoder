#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    float X;
    cin >> X;
    if (X < 37.5) cout << 3 << endl;
    else if (X< 38) cout << 2 << endl;
    else cout << 1 << endl;
}
