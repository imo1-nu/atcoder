#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int X;
    cin >> X;
    for (int i = 1; i <= 3; i++) {
        if (i != X) {
            cout << i << endl;
            break;
        }
    }
}
