#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int X, Y;
    cin >> X >> Y;
    cout << ((X * 9 == Y * 16) ? "Yes" : "No") << endl;
}
