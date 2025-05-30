#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int A, B;
    cin >> A >> B;
    int C = A / B;
    if ((A - B * C) < (B * (C + 1) - A)) cout << C << endl;
    else cout << C + 1 << endl;
}
