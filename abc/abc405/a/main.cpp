#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int R, X;
    cin >> R >> X;
    if (X == 1 && 1600 <= R && R <= 2999 || X == 2 && 1200 <= R && R <= 2399) cout << "Yes" << endl;
    else cout << "No" << endl;
}
