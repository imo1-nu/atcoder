#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S1, S2;
    cin >> S1 >> S2;

    if (S1 == "fine" && S2 == "fine") cout << 4 << endl;
    else if (S1 == "fine" && S2 == "sick") cout << 3 << endl;
    else if (S1 == "sick" && S2 == "fine") cout << 2 << endl;
    else cout << 1 << endl;
}
