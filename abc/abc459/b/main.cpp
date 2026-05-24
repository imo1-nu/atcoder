#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<string> S(N);
    for (auto& s : S) cin >> s;

    for (auto& s : S) {
        int x = s[0] - 'a';
        int res;
        if (x < 3) res = 2;
        else if (x < 6) res = 3;
        else if (x < 9) res = 4;
        else if (x < 12) res = 5;
        else if (x < 15) res = 6;
        else if (x < 19) res = 7;
        else if (x < 22) res = 8;
        else res = 9;
        cout << res;
    }
    cout << endl;
}
