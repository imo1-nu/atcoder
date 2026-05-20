#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    int N;
    cin >> S >> N;
    cout << S.substr(N, S.length() - 2 * N) << endl;
}
