#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    ll no = 0;
    map<int, int> mp;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int c = (a + b) % N;
        no += mp[c]++;
    }
    cout << ll(M) * (M - 1) / 2 - no << endl;
}
