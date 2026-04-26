#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A != B && B == C ? "Yes" : "No") << endl;
}
