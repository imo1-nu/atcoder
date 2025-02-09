#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<int> A(3);
    for (int i = 0; i < 3; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    if (A[0] * A[1] == A[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
