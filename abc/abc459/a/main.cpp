#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int X;
    cin >> X;
    string S = "HelloWorld";
    cout << S.substr(0, X - 1) + S.substr(X, 10 - X) << endl;
}
