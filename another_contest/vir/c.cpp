#include <bits/stdc++.h>
# include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    atcoder::dsu dsu(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        dsu.merge(a, b);
    }

    cout << dsu.groups().size() - 1 << endl;
}
