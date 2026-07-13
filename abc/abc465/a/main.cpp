#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int A, B;
    cin >> A >> B;
    bool ok = (A * 3 > B * 2);
    cout << (ok ? "Yes" : "No") << endl;
}
