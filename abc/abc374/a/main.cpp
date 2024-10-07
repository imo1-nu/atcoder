#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    if (S.substr(S.size() - 3, 3) == "san") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
