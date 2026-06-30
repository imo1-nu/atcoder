#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    int e = 0;
    for (auto c : S) if (c == 'E') e++;
    if (2 * e > S.length()) cout << "East" << endl;
    else cout << "West" << endl;
}
