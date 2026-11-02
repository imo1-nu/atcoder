#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// https://github.com/imo1-nu/atcoder/tree/main/lib

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    int cnt = 0;
    for (auto c : S) if (c == 'o') cnt++;
    if (cnt % 2 == 0) cout << "even" << endl;
    else cout << "odd" << endl;
}
