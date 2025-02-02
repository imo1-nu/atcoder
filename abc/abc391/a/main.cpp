#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    for (auto& c : S) {
        if (c == 'N') c = 'S';
        else if (c == 'S') c = 'N';
        else if (c == 'W') c = 'E';
        else if (c == 'E') c = 'W';
    }
    cout << S << endl;
}
