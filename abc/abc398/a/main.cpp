#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    string S = string((N - 1) / 2, '-');
    string T = string((N + 1) % 2 + 1, '=');
    cout << S << T << S << endl;
}
