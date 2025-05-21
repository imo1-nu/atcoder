#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A > C || (A == C && B > D)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
