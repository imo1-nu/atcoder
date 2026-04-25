#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int M, D;
    cin >> M >> D;
    cout << ((M == 1 && D == 7) || (M == 3 && D == 3) || (M == 5 && D == 5) || (M == 7 && D == 7) || (M == 9 && D == 9) ? "Yes" : "No") << endl;
}
