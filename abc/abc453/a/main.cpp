#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string S;
    cin >> N >> S;
    int i = 0;
    while (S[i] == 'o') i++;
    cout << S.substr(i) << endl;
}
