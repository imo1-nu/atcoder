#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int A;
    cin >> A;
    if (400 % A == 0) cout << 400 / A << endl;
    else cout << -1 << endl;
}
